#include <stdio.h>

// Time complexity: O(sqrt(n))
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
	int n;
	scanf("%d", &n);
	while (n > 9 && !isPrime(n)) {
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		n = sum;
	}
	if (isPrime(n)) {
		printf("%d", n);
	} else {
		printf("0");
	}
	return 0;
}