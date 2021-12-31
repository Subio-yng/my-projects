#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> list(n);
	int sumWeight = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		sumWeight += list[i];
	}
	if (sumWeight % 3 != 0) {
		printf("0");
		return 0;
	}
	sumWeight /= 3;
	std::vector<std::vector<int>> kits(sumWeight + 1);
	for (int curGold = 0; curGold < n; curGold++) {
		for (int curWeight = sumWeight; curWeight >= list[curGold]; curWeight--) {
			if (kits[curWeight - list[curGold]].size() > 0 || curWeight == list[curGold]) {
				kits[curWeight] = kits[curWeight - list[curGold]];
				kits[curWeight].push_back(curGold + 1);
			}
		}
	}
	printf("%d\n", kits[sumWeight].size());
	for (int i = 0; i < (int) kits[sumWeight].size(); i++) {
		printf("%d ", kits[sumWeight][i]);
	}
	return 0;
}