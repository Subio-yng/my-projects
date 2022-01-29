#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
	int m, n, space;
	scanf("%d %d %d", &m, &n, &space);
	if (space < 2 || n / 2 * (space - 2) < m) {
		printf("0");
	} else {
		printf("%d", (n + m + space - 1) / space);
	}
	return 0;
}