#include <stdio.h>
#include <vector>

// Time complexity: O(n * m * move)
// Space complexity: O(n * m)

int main() {
    int n, m, move;
    scanf("%d %d %d", &n, &m, &move);
    std::vector<std::vector<char>> universe(n, std::vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &universe[i][j]);
        }
    }
    for (int k = 0; k < move; k++) {
        std::vector<std::vector<char>> temp = universe;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int countLife = 0;
                int left = j - 1;
                int rigth = j + 1;
                int top = i - 1;
                int bottom = i + 1;
                if (left < 0) {
                    left = m - 1;
                }
                if (rigth == m) {
                    rigth = 0;
                }
                if (top < 0) {
                    top = n - 1;
                }
                if (bottom == n) {
                    bottom = 0;
                }
                if (temp[i][left] == '*') {
                    countLife++;
                }
                if (temp[i][rigth] == '*') {
                    countLife++;
                }
                if (temp[top][j] == '*') {
                    countLife++;
                }
                if (temp[bottom][j] == '*') {
                    countLife++;
                }
                if (temp[top][left] == '*') {
                    countLife++;
                }
                if (temp[top][rigth] == '*') {
                    countLife++;
                }
                if (temp[bottom][left] == '*') {
                    countLife++;
                }
                if (temp[bottom][rigth] == '*') {
                    countLife++;
                }
                if (universe[i][j] == '.' && countLife == 3) {
                    universe[i][j] = '*';
                } else if (universe[i][j] == '*' && countLife != 2 && countLife != 3) {
                    universe[i][j] = '.';
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", universe[i][j]);
        }
        printf("\n");
    }
    return 0;
}