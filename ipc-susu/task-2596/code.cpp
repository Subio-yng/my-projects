#include <stdio.h>
#include <vector>
#include <map>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
	int n, len;
	scanf("%d %d", &n, &len);
	std::map<int, std::vector<int>> list;
	for (int i = 0; i < n; i++) {
		int dish;
		scanf("%d", &dish);
		list[dish].push_back(i);
	}
	int maxCount = 0;
	int greaterDish = 0;
	for (auto curDish : list) {
		int curCount = 1;
		for (int i = 0; i < (int) curDish.second.size() - 1; i++) {
			int j = i + 1;
			while (j < (int) curDish.second.size() &&
				   curDish.second[j] - curDish.second[i] <= len
				   ) {
				j++;
			}
			if (curDish.second[j] - curDish.second[i] > len) {
				curCount++;
			}
			i = j - 1;
		}
		if (curCount > maxCount) {
			greaterDish = curDish.first;
			maxCount = curCount;
		}
	}
	printf("%d %d", greaterDish, maxCount);
	return 0;
}