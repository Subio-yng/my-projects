#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

// Time complexity: O(n * m)
// Space complexity: O(n * m)

void printWay(std::vector<std::vector<int>> &table, int i, int j) {
    j--;
    if (j != 0) {
        if (table[i - 1][j] <= table[i][j] &&
            table[i - 1][j] <= table[i + 1][j]
        ) {
            printWay(table, i - 1, j);
        } else if (table[i][j] <= table[i + 1][j]) {
            printWay(table, i, j);
        } else {
            printWay(table, i + 1, j);
        }
    }
    printf("%d ", i);
}

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    if (sizeI == 0 || sizeJ == 0) {
        return 0;
    }
    std::vector<std::vector<int>> area(sizeI + 1, std::vector<int>(sizeJ + 1));
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            scanf("%d", &area[i][j]);
        }
    }
    std::vector<std::vector<int>> table(sizeI + 2, std::vector<int>(sizeJ + 1, INT_MAX));
    for (int i = 0; i <= sizeI + 1; i++) {
        table[i][0] = 0;
    }
    for (int j = 1; j <= sizeJ; j++) {
        for (int i = 1; i <= sizeI; i++) {
            table[i][j] = std::min({table[i][j - 1], table[i + 1][j - 1], table[i - 1][j - 1]}) + area[i][j];
        }
    }
    int minCostI = 1;
    for (int i = 2; i <= sizeI; i++) {
        if (table[minCostI][sizeJ] > table[i][sizeJ]) {
            minCostI = i;
        }
    }
    printWay(table, minCostI, sizeJ);
    printf("\n%d", table[minCostI][sizeJ]);
    return 0;
}