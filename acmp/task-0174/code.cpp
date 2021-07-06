#include <stdio.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n)

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> spouses(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &spouses[i]);
	}
	double maxMoney;
	scanf("%lf", &maxMoney);
	while (n > 0) {
		int minId = 0;
		for (int i = 1; i < n; i++) {
			if (spouses[i] < spouses[minId]) {
				minId = i;
			}
		}
		double profit = (maxMoney + spouses[minId]) / 2.0;
		if (profit > maxMoney) {
			maxMoney = profit;
		}
		n--;
		std::swap(spouses[minId], spouses[n]);
	}
	printf("%lf", maxMoney);
	return 0;
}