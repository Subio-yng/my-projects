#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<int>> table(sizeI, std::vector<int>(sizeJ));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            scanf("%d", &table[i][j]);
        }
    }
    for (int j = 1; j < sizeJ; j++) {
        table[0][j] += table[0][j - 1];
    }
    for (int i = 1; i < sizeI; i++) {
        table[i][0] += table[i - 1][0];
    }
    for (int i = 1; i < sizeI; i++) {
        for (int j = 1; j < sizeJ; j++) {
            table[i][j] += std::min(table[i - 1][j], table[i][j - 1]);
        }
    }
    printf("%d", table[sizeI - 1][sizeJ - 1]);
    return 0;
}