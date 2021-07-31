#include <stdio.h>
#include <vector>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

struct Cell {

    int move;

    int way;
};

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<Cell>> table(sizeI, std::vector<Cell>(sizeJ));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            scanf("%d", &table[i][j].move);
            table[i][j].way = 0;
        }
    }
    table[0][0].way = 1;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            if (i == sizeI - 1 && j == sizeJ - 1) {
                break;
            }
            if (i + table[i][j].move < sizeI) {
                table[i + table[i][j].move][j].way += table[i][j].way;
            }
            if (j + table[i][j].move < sizeJ) {
                table[i][j + table[i][j].move].way += table[i][j].way;
            }
        }
    }
    printf("%d", table[sizeI - 1][sizeJ - 1].way);
    return 0;
}