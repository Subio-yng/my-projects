#include <stdio.h>

// Space complexity: O(1)

int main() {
	int leftX = -1'000'000'001;
	int rightX = 1'000'000'001;
	int leftY = -1'000'000'001;
	int rightY = 1'000'000'001;
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