#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

// Time complexity: O(sizeI * sizeJ^2)
// Space complexity: O(sizeI * sizeJ)

int getIdMax(std::vector<int> &a) {
    int max = 0;
    for (int i = 1; i < (int) a.size(); i++) {
        if (a[i] >= a[max]) {
            max = i;
        }
    }
    return max;
}

int getRabbitWay(std::vector<std::vector<int>> &area, int &cntCarrot) {
    int sumCarrot = 0;
    int size = (int) area.size();
    int i = 1;
    int j = getIdMax(area[i]);
    while (i < size) {
        if (area[i][j] > 0) {
            sumCarrot += area[i][j];
            area[i][j] = 0;
            cntCarrot--;
        }
        i++;
        if (i < size) {
            if (area[i][j + 1] >= area[i][j] &&
                area[i][j + 1] >= area[i][j - 1]
            ) {
                j++;
            } else if (area[i][j] < area[i][j - 1]) {
                j--;
            }
        }
    }
    return sumCarrot;
}

int getHamsterWay(std::vector<std::vector<int>> &area, 
                  std::vector<std::vector<int>> &plan, 
                  int &cntCarrot
) {
    int sumCarrot = 0;
    int size = (int) plan.size();
    int i = size - 1;
    int j = getIdMax(plan[i]);
    while (i > 0) {
        if (area[i][j] > 0) {
            sumCarrot += area[i][j];
            area[i][j] = 0;
            cntCarrot--;
        }
        i--;
        if (i > 0) {
            if (plan[i][j + 1] >= plan[i][j] &&
                plan[i][j + 1] >= plan[i][j - 1]
            ) {
                j++;
            } else if (plan[i][j] < plan[i][j - 1]) {
                j--;
            }
        }
    }
    return sumCarrot;
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
        rabCarrot += getRabbitWay(area, cntCarrot);
        for (int i = 1; i <= sizeI; i++) {
            for (int j = 1; j <= sizeJ; j++) {
                table[i][j] = area[i][j] + std::max({table[i - 1][j - 1], table[i - 1][j], table[i - 1][j + 1]});
            }
        }
        hamCarrot += getHamsterWay(area, table, cntCarrot);
    }
    printf("%d %d", rabCarrot, hamCarrot);
    return 0;
}