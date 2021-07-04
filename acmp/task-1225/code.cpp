#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int isDigit(int n) {
	if ('0' <= n && n <= '9') {
		return 1;
	}
	return 0;
}

int main() {
	char n1, n2, n3;
	scanf("%c %c %c", &n1, &n2, &n3);
	printf("%d", isDigit(n1) + isDigit(n2) + isDigit(n3));
	return 0;
}