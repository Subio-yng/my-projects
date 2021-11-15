#include <stdio.h>
#include <vector>

// Space complexity: O(n^2)

int getCountStairs(int n,
                   int last,
                   std::vector<std::vector<int>> &dp) {
    if (n == 0) {
        return 1;
    }
    if (dp[n][last] == -1) {
        int count = 0;
        for (int i = last; i <= n; i++) {
            count += getCountStairs(n - i, i + 1, dp);
        }
        dp[n][last] = count;
    }
    return dp[n][last];
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> dp(1 + n, std::vector<int>(1 + n + 1, -1));
    printf("%d", getCountStairs(n, 1, dp));
    return 0;
}