#include <bits/stdc++.h>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

void printWay(int i, int j, int sizeJ, const std::vector<std::vector<long long>> &minSum) {
    if (i != 0) {
        long long min = minSum[i - 1][j];
        if (j > 0) {
            min = std::min(min, minSum[i][j - 1]);
        }
        if (j < sizeJ - 1) {
            min = std::min(min, minSum[i][j + 1]);
        }
        if (j > 0 && min == minSum[i][j - 1]) {
            printWay(i, j - 1, sizeJ, minSum);
        } else if (j < sizeJ - 1 && min == minSum[i][j + 1]) {
            printWay(i, j + 1, sizeJ, minSum);
        } else {
            printWay(i - 1, j, sizeJ, minSum);
        }
    }
    printf("%d ", j + 1);
}

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<int>> field(sizeI, std::vector<int>(sizeJ));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            scanf("%d", &field[i][j]);
        }
    }
    std::vector<std::vector<long long>> minSum(sizeI, std::vector<long long>(sizeJ, LLONG_MAX));
    for (int j = 0; j < sizeJ; j++) {
        minSum[0][j] = field[0][j];
    }
    for (int i = 1; i < sizeI; i++) {
        minSum[i][0] = field[i][0] + minSum[i - 1][0];
        for (int j = 1; j < sizeJ; j++) {
            minSum[i][j] = field[i][j] + std::min(minSum[i - 1][j], minSum[i][j - 1]);
        }
        minSum[i][sizeJ - 1] = std::min(minSum[i][sizeJ - 1], minSum[i - 1][sizeJ - 1] + field[i][sizeJ - 1]);
        for (int j = sizeJ - 2; j >= 0; j--) {
            minSum[i][j] = std::min(minSum[i][j], minSum[i][j + 1] + field[i][j]);
        }
    }
    int bestJ = 0;
    for (int j = 1; j < sizeJ; j++) {
        if (minSum[sizeI - 1][j] < minSum[sizeI - 1][bestJ]) {
            bestJ = j;
        }
    }
    printWay(sizeI - 1, bestJ, sizeJ, minSum);
    return 0;
}