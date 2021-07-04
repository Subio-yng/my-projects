#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

long long F(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * F(n - 1);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%lld", F(n) / (F(k) * F(n - k)));
	return 0;
}