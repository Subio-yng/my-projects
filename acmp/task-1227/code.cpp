#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

long long getF(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * getF(n - 1);
}

long long getC(int n, int k) {
	return getF(n) / (getF(k) * getF(n - k));
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%lld", getC(n, k));
	return 0;
}