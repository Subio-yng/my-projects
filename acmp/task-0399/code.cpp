#include <stdio.h>
#include <algorithm>
#include <vector>

// Time complexity: O(n * m)
// Space complexity: O(n * m)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d ", &n, &m);
    std::vector<std::vector<int>> maze(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            char temp;
            scanf("%c", &temp);
            if (temp == '@') {
                maze[i][j] = 10000000;
            } else if (temp == ' ') {
                maze[i][j] = 0;
            }
        }
    }
    if (maze[1][2] == '@' && maze[2][1] == '@') {
        printf("-1");
        return 0;
    }
    int xBug = 1, yBug = 1;
    int move = 0, direction = 1;
    while (xBug != m - 2 || yBug != n - 2) {
        if (move > 10000000) {
            printf("-1");
            return 0;
        }
        int minCount = std::min({maze[yBug][xBug - 1], maze[yBug][xBug + 1], maze[yBug - 1][xBug], maze[yBug + 1][xBug]});
        maze[yBug][xBug]++;
        if (direction == 1 && minCount == maze[yBug + 1][xBug]) {
            yBug++;
        } else if (direction == 2 && minCount == maze[yBug][xBug + 1]) {
            xBug++;
        } else if (direction == 3 && minCount == maze[yBug - 1][xBug]) {
            yBug--;
        } else if (direction == 4 && minCount == maze[yBug][xBug - 1]) {
            xBug--;
        } else if (minCount == maze[yBug + 1][xBug]) {
            yBug++;
            direction = 1;
        } else if (minCount == maze[yBug][xBug + 1]) {
            xBug++;
            direction = 2;
        } else if (minCount == maze[yBug - 1][xBug]) {
            yBug--;
            direction = 3;
        } else {
            xBug--;
            direction = 4;
        }
        move++;
    }
    printf("%d", move);
    return 0;
}