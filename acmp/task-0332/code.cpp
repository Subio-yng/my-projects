#include <stdio.h>
#include <algorithm>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> cost(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    std::vector<int> minCost(n + 1);
    minCost[0] = 0;
    for (int i = 0; i < n; i++) {
        minCost[i + 1] = cost[0][i];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            minCost[i] = std::min(minCost[i], minCost[j] + cost[j][i - 1]);
        }
    }
    printf("%d", minCost[n]);
    return 0;
}