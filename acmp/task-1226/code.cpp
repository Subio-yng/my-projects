#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int IsLetter(int n) {
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
	printf("%d", IsLetter(n1) + IsLetter(n2) + IsLetter(n3));
	return 0;
}