#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int IsDigit(int n) {
	if ('0' <= n && n <= '9') {
		return 1;
	}
	return 0;
}

int main() {
	char n1, n2, n3;
	scanf("%c %c %c", &n1, &n2, &n3);
	printf("%d", IsDigit(n1) + IsDigit(n2) + IsDigit(n3));
	return 0;
}