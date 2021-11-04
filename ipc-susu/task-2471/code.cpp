#include <stdio.h>
#include <algorithm>

// Time complexity: O(log(n))
// Space complexity: O(1)

int main() {
	int n;
	scanf("%d", &n);
	int p1 = 0;
	while (n % 2 == 0) {
		n /= 2;
		p1++;
	}
	int p2 = 0;
	while (n % 5 == 0) {
		n /= 5;
		p2++;
	}
	if (n > 1) {
		printf("NO");
	} else {
		printf("%d", std::max(p1, p2));
	}
	return 0;
}