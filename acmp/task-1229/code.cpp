#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

struct Point {

	int x;

	int y;
};

int side(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
	Point n1, n2, n3;
	scanf("%d %d %d %d %d %d", &n1.x, &n1.y, &n2.x, &n2.y, &n3.x, &n3.y);
	if (side(n1, n2) + side(n1, n3) == side(n2, n3) ||
		side(n2, n3) + side(n2, n1) == side(n1, n3) ||
		side(n3, n1) + side(n3, n2) == side(n1, n2)
		) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}