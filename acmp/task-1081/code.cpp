#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
	int n;
	scanf("%d", &n);
	std::vector<long long> prefixSum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &prefixSum[i]);
		prefixSum[i] += prefixSum[i - 1];
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int left, right;
		scanf("%d %d", &left, &right);
		printf("%lld ", prefixSum[right] - prefixSum[left - 1]);
	}
	return 0;
}