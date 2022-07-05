#include <stdio.h>
#include <vector>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

int main() {
	int sizeI, sizeJ, q;
	scanf("%d %d %d", &sizeI, &sizeJ, &q);
	std::vector<std::vector<long long>> prefixSum(sizeI + 1, std::vector<long long>(sizeJ + 1, 0));
	for (int i = 1; i <= sizeI; i++) {
		for (int j = 1; j <= sizeJ; j++) {
			scanf("%d", &prefixSum[i][j]);
			prefixSum[i][j] += prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
		}
	}
	for (int i = 0; i < q; i++) {
		int i1, j1, i2, j2;
		scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
		printf("%lld\n", prefixSum[i2][j2] - prefixSum[i2][j1 - 1] - prefixSum[i1 - 1][j2] + prefixSum[i1 - 1][j1 - 1]);
	}
	return 0;
}