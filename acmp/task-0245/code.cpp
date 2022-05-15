#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> list(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	std::sort(list.begin(), list.end());
	int curSum = 0;
	int maxSum = 0;
	int left = 0;
	int right = 0;
	while (right < n) {
		if (left + 1 < n && list[left] + list[left + 1] < list[right]) {
			curSum -= list[left];
			left++;
		} else {
			curSum += list[right];
			right++;
		}
		maxSum = std::max(maxSum, curSum);
	}
	printf("%d", maxSum);
	return 0;
}