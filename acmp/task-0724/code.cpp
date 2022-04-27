#include <stdio.h>
#include <vector>

// Time complexity: O(2^sizeJ * sizeI)
// Space complexity: O(sizeJ)

int main() {
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	std::vector<int> table(sizeJ, 0);
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			char val;
			scanf(" %c", &val);
			table[j] += val - '0';
			table[j] <<= 1;
		}
	}
	for (int j = 0; j < sizeJ; j++) {
		table[j] >>= 1;
	}
	int bestAttack = 0;
	int minStep = 0;
	for (int attack = 1; attack < 1 << sizeJ; attack++) {
		std::vector<int> curAttack;
		int curStep = 0;
		int defense = (1 << sizeI) - 1;
		for (int j = 0; j < sizeJ; j++) {
			if ((attack >> j) & 1 != 0) {
				curStep++;
				defense &= table[sizeJ - j - 1];
			}
		}
		if (defense == 0 && (minStep == 0 || minStep > curStep)) {
			bestAttack = attack;
			minStep = curStep;
		}
	}
	std::vector<int> ans;
	for (int j = sizeJ; j > 0; j--) {
		if (bestAttack % 2 == 1) {
			ans.push_back(j);
		}
		bestAttack >>= 1;
	}
	if (ans.empty()) {
		printf("Impossible");
	} else {
		printf("%d\n", (int) ans.size());
		for (int next : ans) {
			printf("%d ", next);
		}
	}
	return 0;
}