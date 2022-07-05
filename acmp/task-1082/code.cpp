#include <stdio.h>
#include <vector>

// Time complexity: O(sizeI * q)
// Space complexity: O(sizeI * sizeJ)

int main() {
	int sizeI, sizeJ, q;
	scanf("%d %d %d", &sizeI, &sizeJ, &q);
	std::vector<std::vector<int>> prefixSum(sizeI + 1, std::vector<int>(sizeJ + 1, 0));
	for (int i = 1; i <= sizeI; i++) {
		for (int j = 1; j <= sizeJ; j++) {
			int cur;
			scanf("%d", &cur);
			prefixSum[i][j] = prefixSum[i - 1][j] + cur;
		}
	}
	for (int i = 0; i < q; i++) {
		int y1, x1, y2, x2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		long long sum = 0;
		for (int j = x1; j <= x2; j++) {
			sum += prefixSum[y2][j] - prefixSum[y1 - 1][j];
		}
		printf("%lld\n", sum);
	}
	return 0;
}