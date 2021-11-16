#include <stdio.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
	int n, a, b, c;
	scanf("%d %d %d %d", &n, &a, &b, &c);
	int k = 1;
	if (a + 1 == b || b + 1 != c) {
		do {
			k++;
			if (a + 1 == b) {
				a = b;
				b = c;
			} else {
				break;
			}
			if (k < n - 1) {
				scanf("%d", &c);
			}
		} while (k < n);
	}
	printf("%d", k);
	return 0;
}