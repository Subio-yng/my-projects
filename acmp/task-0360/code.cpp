#include <stdio.h>
#include <algorithm>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<short int>> table(n, std::vector<short int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%hi", &table[i][j]);
        }
    }
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 1 && table[i][j] + table[i - 1][j] + table[i - 2][j] > maxSum) {
                maxSum = table[i][j] + table[i - 1][j] + table[i - 2][j];
            }
            if (j > 1 && table[i][j] + table[i][j - 1] + table[i][j - 2] > maxSum) {
                maxSum = table[i][j] + table[i][j - 1] + table[i][j - 2];
            }
            if (i + 2 < n && table[i][j] + table[i + 1][j] + table[i + 2][j] > maxSum) {
                maxSum = table[i][j] + table[i + 1][j] + table[i + 2][j];
            }
            if (j + 2 < n && table[i][j] + table[i][j + 1] + table[i][j + 2] > maxSum) {
                maxSum = table[i][j] + table[i][j + 1] + table[i][j + 2];
            }
            if (i > 0 && j > 0 &&
                table[i][j] + std::max(table[i - 1][j], table[i][j - 1]) + table[i - 1][j - 1] > maxSum
            ) {
                maxSum = table[i][j] + std::max(table[i - 1][j], table[i][j - 1]) + table[i - 1][j - 1];
            }
            if (i > 0 && j + 1 < n &&
                table[i][j] + std::max(table[i - 1][j], table[i][j + 1]) + table[i - 1][j + 1] > maxSum
            ) {
                maxSum = table[i][j] + std::max(table[i - 1][j], table[i][j + 1]) + table[i - 1][j + 1];
            }
            if (i + 1 < n && j > 0 &&
                table[i][j] + std::max(table[i][j - 1], table[i + 1][j]) + table[i + 1][j - 1] > maxSum
            ) {
                maxSum = table[i][j] + std::max(table[i][j - 1], table[i + 1][j]) + table[i + 1][j - 1];
            }
            if (i + 1 < n && j + 1 < n &&
                table[i][j] + std::max(table[i + 1][j], table[i][j + 1]) + table[i + 1][j + 1] > maxSum
            ) {
                maxSum = table[i][j] + std::max(table[i + 1][j], table[i][j + 1]) + table[i + 1][j + 1];
            }
        }
    }
    printf("%d", maxSum);
    return 0;
}