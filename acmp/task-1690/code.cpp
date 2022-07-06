#include <stdio.h>
#include <vector>

// Time complexity: O(sizeZ * sizeI * sizeJ + q)
// Space complexity: O(sizeZ * sizeI * sizeJ)

int main() {
    int sizeZ, sizeI, sizeJ, q;
    scanf("%d %d %d %d", &sizeZ, &sizeI, &sizeJ, &q);
    std::vector<std::vector<std::vector<int>>> prefSum(sizeZ + 1, std::vector<std::vector<int>>(sizeI + 1, std::vector<int>(sizeJ + 1, 0)));
    for (int z = 1; z <= sizeZ; z++) {
        for (int i = 1; i <= sizeI; i++) {
            for (int j = 1; j <= sizeJ; j++) {
                char val;
                scanf(" %c", &val);
                prefSum[z][i][j] = val - '0' + prefSum[z - 1][i][j] + prefSum[z][i - 1][j] + prefSum[z][i][j - 1] + prefSum[z - 1][i - 1][j - 1] - prefSum[z][i - 1][j - 1] - prefSum[z - 1][i][j - 1] - prefSum[z - 1][i - 1][j];
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int z1, i1, j1, z2, i2, j2;
        scanf("%d %d %d %d %d %d", &z1, &i1, &j1, &z2, &i2, &j2);
        if (z1 > z2) {
            std::swap(z1, z2);
        }
        if (i1 > i2) {
            std::swap(i1, i2);
        }
        if (j1 > j2) {
            std::swap(j1, j2);
        }
        int curSum = prefSum[z2][i2][j2] - prefSum[z1 - 1][i2][j2] - prefSum[z2][i1 - 1][j2] - prefSum[z2][i2][j1 - 1] - prefSum[z1 - 1][i1 - 1][j1 - 1] + prefSum[z2][i1 - 1][j1 - 1] + prefSum[z1 - 1][i2][j1 - 1] + prefSum[z1 - 1][i1 - 1][j2];
        printf("%d\n", curSum);
    }
    return 0;
}