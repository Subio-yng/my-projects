#include <stdio.h>

// Time complexity: O(lg(n))
// Space complexity: O(1)

int main() {
	int n;
	scanf("%d", &n);
	int k = 0;
	while (n > 9) {
		k++;
		int m = 1;
		while (n > 0) {
			m *= n % 10;
			n /= 10;
		}
		n = m;
	}
	printf("%d %d", k, n);
	return 0;
}