#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n^3)
// Space complexity: O(n^2)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> area(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &area[i][j]);
        }
    }
    std::vector<std::vector<int>> table(n + 1, std::vector<int>(n + 1, 0));
    for (int j = 1; j <= n; j++) {
        for (int curSum = 1; curSum <= n; curSum++) {
            for (int i = 0; i <= curSum; i++) {
                table[curSum][j] = std::max(table[curSum][j], table[curSum - i][j - 1] + area[i][j]);
            }
        }
    }
    printf("%d", table[n][n]);
    return 0;
}