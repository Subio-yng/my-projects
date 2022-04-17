#include <stdio.h>

// Time complexity: O(n * sqrt(n))
// Space complexity: O(1)

bool isPrime(int n) {
	for (int i = 2; i <= n / i; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return n > 1;
}

int main() {
	int left, right;
	scanf("%d %d", &left, &right);
	bool ans = false;
	for (int i = left; i <= right; i++) {
		if (isPrime(i)) {
			printf("%d ", i);
			ans = true;
		}
	}
	if (!ans) {
		printf("Absent");
	}
	return 0;
}