#include <stdio.h>

// Time complexity: O(n^3)
// Space complexity: O(1)

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int a = 1; a < n; a++) {
		for (int b = a; b < n; b++) {
			for (int c = b; c < n; c++) {
				if (a + b + c < n && n - a - b - c >= c) {
					ans++;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}