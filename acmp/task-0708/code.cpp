#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

// Time complexity: O(sizeI * sizeJ^2)
// Space complexity: O(sizeI * sizeJ^2)

int getIdMax(std::vector<int> a) {
    int max = 0;
    for (int i = 1; i < (int) a.size(); i++) {
        if (a[i] >= a[max]) {
            max = i;
        }
    }
    return max;
}

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<int>> area(sizeI + 1, std::vector<int>(sizeJ + 2, INT_MIN));
    int cntCarrot = 0;
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            scanf("%d", &area[i][j]);
            if (area[i][j] > 0) {
                cntCarrot++;
            }
        }
    }
    std::vector<std::vector<int>> table(sizeI + 1, std::vector<int>(sizeJ + 2, INT_MIN));
    for (int j = 0; j <= sizeJ + 1; j++) {
        table[0][j] = 0;
    }
    int rabCarrot = 0, hamCarrot = 0;
    while (cntCarrot > 0) {
        int curI = 1;
        int curJ = getIdMax(area[curI]);
        while (curI <= sizeI) {
            if (area[curI][curJ] > 0) {
                rabCarrot += area[curI][curJ];
                area[curI][curJ] = 0;
                cntCarrot--;
            }
            curI++;
            if (curI <= sizeI) {
                if (area[curI][curJ + 1] >= area[curI][curJ] &&
                    area[curI][curJ + 1] >= area[curI][curJ - 1]
                    ) {
                    curJ++;
                } else if (area[curI][curJ] < area[curI][curJ - 1]) {
                    curJ--;
                }
            }
        }
        for (int i = 1; i <= sizeI; i++) {
            for (int j = 1; j <= sizeJ; j++) {
                table[i][j] = area[i][j] + std::max({table[i - 1][j - 1], table[i - 1][j], table[i - 1][j + 1]});
            }
        }
        curI--;
        curJ = getIdMax(table[curI]);
        while (curI >= 1) {
            if (area[curI][curJ] > 0) {
                hamCarrot += area[curI][curJ];
                area[curI][curJ] = 0;
                cntCarrot--;
            }
            curI--;
            if (curI >= 1) {
                if (table[curI][curJ + 1] >= table[curI][curJ] &&
                    table[curI][curJ + 1] >= table[curI][curJ - 1]
                    ) {
                    curJ++;
                } else if (table[curI][curJ] < table[curI][curJ - 1]) {
                    curJ--;
                }
            }
        }
    }
    printf("%d %d", rabCarrot, hamCarrot);
    return 0;
}