#include <stdio.h>
#include <algorithm>

// Time complexity: O(sqrt(n) + log(n))
// Space complexity: O(1)

bool isPrimeDiv(int n) {
	for (int i = 2; i <= n / i; i++) {
		if (n % i == 0) {
			n /= i;
			i = 1;
		}
	}
	return n > 5;
}

int main() {
	int n;
	scanf("%d", &n);
	if (n % 3 == 0 || isPrimeDiv(n)) {
		printf("NO");
	} else {
		int p1 = 0;
		for (int temp = n; temp % 2 == 0; temp /= 2) {
			p1++;
		}
		int p2 = 0;
		for (int temp = n; temp % 5 == 0; temp /= 5) {
			p2++;
		}
		printf("%d", std::max(p1, p2));
	}
	return 0;
}