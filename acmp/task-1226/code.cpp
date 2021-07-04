#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int isLetter(int n) {
	if ('a' <= n && n <= 'z' ||
		'A' <= n && n <= 'Z'
	) {
		return 1;
	}
	return 0;
}

int main() {
	char n1, n2, n3;
	scanf("%c %c %c", &n1, &n2, &n3);
	printf("%d", isLetter(n1) + isLetter(n2) + isLetter(n3));
	return 0;
}