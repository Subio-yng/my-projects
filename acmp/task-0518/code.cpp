#include <stdio.h>
#include <vector>
 
// Time complexity: O(move * n^2)
// Space complexity: O(move * n^2)

int main() {
    int n, move;
    scanf("%d %d", &n, &move);
    std::vector<std::vector<char>> field(n, std::vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &field[i][j]);
        }
    }
    std::vector<std::vector<std::vector<int>>> ways(move + 1, std::vector<std::vector<int>>(n, std::vector<int>(n, 0)));
    ways[0][0][0] = 1;
    for (int len = 1; len <= move; len++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (field[i][j] == '0') {
                    if (j > 0) {
                        ways[len][i][j] += ways[len - 1][i][j - 1];
                    }
                    if (i > 0) {
                        ways[len][i][j] += ways[len - 1][i - 1][j];
                    }
                    if (j + 1 < n) {
                        ways[len][i][j] += ways[len - 1][i][j + 1];
                    }
                    if (i + 1 < n) {
                        ways[len][i][j] += ways[len - 1][i + 1][j];
                    }
                }
            }
        }
    }
    printf("%d", ways[move][n - 1][n - 1]);
    return 0;
}