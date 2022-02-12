#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

// Time complexity: O(n * m)
// Space complexity: O(n * m)

std::string getWay(std::vector<std::vector<int>> table, int i, int j) {
    std::string way;
    while (j != 0) {
        std::string curNum = std::to_string(i);
        std::reverse(curNum.rbegin(), curNum.rend());
        way += ' ' + curNum;
        j--;
        int curMin = std::min({table[i - 1][j], table[i][j], table[i + 1][j]});
        if (table[i - 1][j] == curMin) {
            i--;
        } else if (table[i][j] != curMin && table[i + 1][j] == curMin) {
            i++;
        }
    }
    return {way.rbegin(), way.rend()};
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
    int minCost = INT_MAX;
    for (int i = 1; i <= sizeI; i++) {
        minCost = std::min(minCost, table[i][sizeJ]);
    }
    std::string bestWay;
    for (int i = 1; i <= sizeI; i++) {
        if (minCost == table[i][sizeJ]) {
            if (bestWay.empty()) {
                bestWay = getWay(table, i, sizeJ);
            } else {
                bestWay = std::min(bestWay, getWay(table, i, sizeJ));
            }
        }
    }
    printf("%s", bestWay.c_str());
    printf("\n%d", minCost);
    return 0;
}