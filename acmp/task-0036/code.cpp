#include <stdio.h>

// Time complexity: O(n * sqrt(n))
// Space complexity: O(1)

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return n > 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int countPrime = 0;
	for (int i = n + 1; i < n << 1; i++) {
		if (isPrime(i)) {
			countPrime++;
		}
	}
	printf("%d", countPrime);
	return 0;
}