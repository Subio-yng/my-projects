#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    std::vector<long long> dp(n + 1, 1);
    for (int i = m; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - m];
    }
    printf("%lld", dp[n]);
    return 0;
}