#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 1; i < n; i++) {
        dp[i + 1] = std::min(dp[i + 1], dp[i] + 1);
        if (2 * i <= n) {
            dp[2 * i] = std::min(dp[2 * i], dp[i] + 1);
            if (3 * i <= n) {
                dp[3 * i] = std::min(dp[3 * i], dp[i] + 1);
            }
        }
    }
    printf("%d", dp[n]);
    return 0;
}