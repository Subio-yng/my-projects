#include <stdio.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
	freopen("intput.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, mod;
	scanf("%d %d", &n, &mod);
	int ans = 2 % mod;
	for (int i = 0; i < n; i++) {
		ans *= ans;
		ans %= mod;
	}
	printf("%d", ans);
	return 0;
}