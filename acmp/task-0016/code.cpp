#include <stdio.h>
#include <vector>

// Space complexity: O(n^2)

std::vector<std::vector<int>> dp;

int labber(int n, int last) {
    if (n < 3) {
        return 0;
    }
    if (dp[n][last] != -1) {
        return dp[n][last];
    }
    int count = 0;
    for (int i = last; i < n - i; i++) {
        count += labber(n - i, i + 1);
        count++;
    }
    dp[n][last] = count;
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    dp.resize(n + 1, std::vector<int>(n + 1, -1));
    printf("%d", labber(n, 1) + 1);
    return 0;
}