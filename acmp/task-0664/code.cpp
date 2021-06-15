#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int space, sideTime, cutlets;
	scanf("%d %d %d", &space, &sideTime, &cutlets);
	int ans = (cutlets << 1) / space;
	if ((cutlets << 1) % space > 0) {
		ans++;
	}
	ans = std::max(ans, 2);
	ans *= sideTime;
	printf("%d", ans);
	return 0;
}