#include <stdio.h>

// Time complexity: O(n^2)
// Space complexity: O(1)

int main() {
	int n;
	scanf("%d", &n);
	int count = 0;
	for (int a = 1; a * 4 <= n; a++) {
		for (int b = a; a + b * 3 <= n; b++) {
			int minC = b;
			int maxC = (n - a - b) / 2;
			count += maxC - minC + 1;
		}
	}
	printf("%d", count);
	return 0;
}