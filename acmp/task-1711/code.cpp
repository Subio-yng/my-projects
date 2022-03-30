#include <stdio.h>

// Time complexity: O(log(range))
// Space complexity: O(1)

int main() {
	const int INF = 1'000'000'000 + 1;
	int leftX = -INF;
	int rightX = INF;
	int leftY = -INF;
	int rightY = INF;
	int x, y;
	do {
		int midX = (leftX + rightX) / 2;
		int midY = (leftY + rightY) / 2;
		printf("%d %d\n", midX, midY);
		fflush(stdout);
		scanf("%d %d", &x, &y);
		if (x < 0) {
			leftX += x;
			rightX = midX;
		} else if (x > 0) {
			rightX += x;
			leftX = midX;
		}
		if (y < 0) {
			leftY += y;
			rightY = midY;
		} else if (y > 0) {
			rightY += y;
			leftY = midY;
		}
	} while (x != 0 || y != 0);
	return 0;
}