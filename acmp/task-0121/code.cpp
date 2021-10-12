#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> tablet(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tablet[i]);
	}
	std::sort(tablet.begin(), tablet.end());
	std::vector<int> minLen(n);
	minLen[1] = tablet[1] - tablet[0];
	minLen[2] = tablet[2] - tablet[0];
	for (int i = 3; i < n; i++) {
		minLen[i] = std::min(minLen[i - 2], minLen[i - 1]) + (tablet[i] - tablet[i - 1]);
	}
	printf("%d", minLen[n - 1]);
	return 0;
}