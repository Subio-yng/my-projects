#include <stdio.h>
#include <algorithm>
#include <math.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int space, sideTime, cutlets;
	scanf("%d %d %d", &space, &sideTime, &cutlets);
	printf("%d", std::max((cutlets << 1) / space + ((cutlets << 1) % space > 0), 2) * sideTime);
	return 0;
}