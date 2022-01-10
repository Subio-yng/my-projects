#include <stdio.h>
#include <algorithm>
#include <vector>
#include <climits>

int main() {
    int nBlocks;
    scanf("%d", &nBlocks);
    std::vector<int> leftPar(nBlocks + 1);
    std::vector<int> rightPar(nBlocks + 1);
    for (int i = 1; i <= nBlocks; i++) {
        scanf("%d %d", &leftPar[i], &rightPar[i]);
    }
    std::vector<std::vector<int>> minCost(nBlocks + 1, std::vector<int>(nBlocks + 1));
    for (int len = 1; len <= nBlocks; len++) {
        for (int left = 1; left + len - 1 <= nBlocks; left++) {
            int right = left + len - 1;
            if (len == 1) {
                minCost[left][right] = 0;
            } else {
                int min = INT_MAX;
                for (int right1 = left; right1 < right; right1++) {
                    int left1 = right1 + 1;
                    min = std::min(min, minCost[left][right1] + minCost[left1][right]);
                }
                minCost[left][right] = min + leftPar[left] * rightPar[right];
            }
        }
    }
    printf("%d", minCost[1][nBlocks]);
    return 0;
}