#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<long long> prefixSum(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &prefixSum[i]);
        if (i > 0) {
            prefixSum[i] += prefixSum[i - 1];
        }
    }
    long long minDiff = prefixSum[n - 1];
    int bestId = -1;
    for (int i = 0; i < n; i++) {
        long long curDiff = abs(prefixSum[n - 1] - 2 * prefixSum[i]);
        if (curDiff < minDiff) {
            minDiff = curDiff;
            bestId = i;
        }
    }
    printf("%d", bestId + 1);
    return 0;
}