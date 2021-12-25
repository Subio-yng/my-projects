#include <stdio.h>
#include <vector>

// Time complexity: O(n * k)
// Space complexity: O(k)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    int k;
    scanf("%d", &k);
    std::vector<int> dp(k + 1, -1);
    dp[0] = 0;
    for (int cur = 1; cur <= k; cur++) {
        for (int prev = 0; prev < n; prev++) {
            if (list[prev] <= cur && dp[cur - list[prev]] > -1 &&
                (dp[cur - list[prev]] + 1 < dp[cur] || dp[cur] == -1)
            ) {
                dp[cur] = dp[cur - list[prev]] + 1;
            }
        }
    }
    printf("%d", dp[k]);
    return 0;
}