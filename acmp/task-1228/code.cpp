#include <stdio.h>

// Time complexity: O(sqrt(n1) + sqrt(n2) + sqrt(n3))
// Space complexity: O(1)

int isPrime(int n) {
	if (n < 2) {
		return 0;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return n;
}

int main() {
	int n1, n2, n3;
	scanf("%d %d %d", &n1, &n2, &n3);
	int sumPrime = isPrime(n1) + isPrime(n2) + isPrime(n3);
	printf("%d\n", sumPrime);
	if (isPrime(sumPrime) != 0) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}