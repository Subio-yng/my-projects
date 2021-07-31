#include <stdio.h>
#include <vector>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<int>> tableMove(sizeI, std::vector<int>(sizeJ));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            scanf("%d", &tableMove[i][j]);
        }
    }
    std::vector<std::vector<int>> tableWay(sizeI, std::vector<int>(sizeJ, 0));
    tableWay[0][0] = 1;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            if (i == sizeI - 1 && j == sizeJ - 1) {
                break;
            }
            if (i + tableMove[i][j] < sizeI) {
                tableWay[i + tableMove[i][j]][j] += tableWay[i][j];
            }
            if (j + tableMove[i][j] < sizeJ) {
                tableWay[i][j + tableMove[i][j]] += tableWay[i][j];
            }
        }
    }
    printf("%d", tableWay[sizeI - 1][sizeJ - 1]);
    return 0;
}