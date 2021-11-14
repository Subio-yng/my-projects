#include <stdio.h>

// Time complexity: O(n)
// Space complexity: O(1)

void labber(int n, int last, int &count) {
	for (int i = last; i < n - i; i++) {
		labber(n - i, i + 1, count);
		count++;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int count = 1;
	labber(n, 1, count);
	printf("%d", count);
	return 0;
}