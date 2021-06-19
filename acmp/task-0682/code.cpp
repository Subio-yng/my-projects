#include <stdio.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("45");
	} else if (n == 2) {
		printf("4905");
	} else {
		printf("494");
		for (int i = 3; i < n; i++) {
			printf("9");
		}
		printf("55");
		for (int i = 2; i < n; i++) {
			printf("0");
		}
	}
	return 0;
}