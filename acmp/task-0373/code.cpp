#include <stdio.h>
#include <vector>
#include <algorithm>
 
// Time complexity: O(move * n^2)
// Space complexity: O(move * n)

int main() {
    int n, move;
    scanf("%d %d", &n, &move);
    std::vector<std::vector<int>> field(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &field[i][j]);
        }
    }
    std::vector<std::vector<int>> sum(n, std::vector<int>(n, 0));
    sum[0][0] = field[0][0];
    std::vector<std::vector<int>> prevSum = sum;
    for (int len = 1; len < move; len++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int curMax = 0;
                if (j > 0) {
                    curMax = prevSum[i][j - 1];
                }
                if (i > 0) {
                    curMax = std::max(curMax, prevSum[i - 1][j]);
                }
                if (j + 1 < n) {
                     curMax = std::max(curMax, prevSum[i][j + 1]);
                }
                if (i + 1 < n) {
                     curMax = std::max(curMax, prevSum[i + 1][j]);
                }
                if (curMax > 0) {
                    sum[i][j] = field[i][j] + curMax;
                }
            }
        }
        prevSum = sum;
    }
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maxSum = std::max(maxSum, sum[i][j]);
        }
    }
    printf("%d", maxSum);
    return 0;
}