#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int ceilDiv(int a, int b) {
	return (a + b - 1) / b;
}

int main() {
	int m, n, space;
	scanf("%d %d %d", &m, &n, &space);
	if (space < 2 || n / 2 * (space - 2) < m) {
		printf("0");
	} else {
		printf("%d", ceilDiv(n + m, space));
	}
	return 0;
}