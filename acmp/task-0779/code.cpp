#include <stdio.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int mid = n >> 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int house;
		scanf("%d", &house);
		if (i == mid) {
			ans = house;
		}
	}
	printf("%d", ans);
	return 0;
}
