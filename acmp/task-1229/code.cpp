#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

struct Point {

	int x;

	int y;

	static Point read() {
		Point a;
		scanf("%d %d", &a.x, &a.y);
		return a;
	}
};

int side(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
	Point n1 = Point::read();
	Point n2 = Point::read();
	Point n3 = Point::read();
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