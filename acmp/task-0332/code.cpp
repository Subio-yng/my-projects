#include <stdio.h>
#include <algorithm>
#include <vector>
#include <climits>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> cost(n, std::vector<int>(n + 1));
    for (int cur = 0; cur < n; cur++) {
        for (int next = cur + 1; next <= n; next++) {
            scanf("%d", &cost[cur][next]);
        }
    }
    std::vector<int> minCost(n + 1, INT_MAX);
    minCost[0] = 0;
    for (int cur = 1; cur <= n; cur++) {
        for (int prev = 0; prev < cur; prev++) {
            minCost[cur] = std::min(minCost[cur], minCost[prev] + cost[prev][cur]);
        }
    }
    printf("%d", minCost[n]);
    return 0;
}