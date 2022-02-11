#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

int main() {
    const int INF = 251 * 9;
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> table(n + 1, std::vector<int>(n + 1, INF));
    table[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char curCell;
            scanf(" %c", &curCell);
            table[i][j] = curCell - '0' + std::min(table[i][j - 1], table[i - 1][j]);
        }
    }
    std::vector<std::vector<char>> way(n, std::vector<char>(n, '.'));
    int i = n;
    int j = n;
    while (i != 1 || j != 0) {
        way[i - 1][j - 1] = '#';
        if (table[i - 1][j] < table[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", way[i][j]);
        }
        printf("\n");
    }
    return 0;
}