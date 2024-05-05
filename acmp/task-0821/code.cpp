#include <bits/stdc++.h>

// Time complexity: O(n^2 + len)
// Space complexity: O(n^2 + len)

int main() {
    int n;
    scanf("%d", &n);
    char buf[1 + 10'000];
    scanf(" %s", &buf);
    std::string cmd(buf);
    std::vector<std::vector<int>> field(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        std::iota(field[i].begin(), field[i].end(), 1 + i * n);
    }
    field[n - 1][n - 1] = 0;
    int posI = n - 1;
    int posJ = n - 1;
    for (int i = 0; i < (int) cmd.length(); i++) {
        int nextI = posI;
        int nextJ = posJ;
        if (cmd[i] == 'U') {
            nextI--;
        } else if (cmd[i] == 'L') {
            nextJ--;
        } else if (cmd[i] == 'D') {
            nextI++;
        } else {
            nextJ++;
        }
        if (0 <= nextI && nextI < n &&
            0 <= nextJ && nextJ < n
        ) {
            std::swap(field[posI][posJ], field[nextI][nextJ]);
            posI = nextI;
            posJ = nextJ;
        } else {
            printf("ERROR %d", i + 1);
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }
    return 0;
}