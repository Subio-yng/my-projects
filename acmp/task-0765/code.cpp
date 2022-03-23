#include <stdio.h>
#include <vector>
 
// Time complexity: O(n^2)
// Space complexity: O(n^2)

enum Part {
    UNMARKED, WHITE, BLACK
};

void dfs(int curI,
         int curJ,
         int size,
         int &countDame,
         std::vector<std::vector<bool>> &visited,
         std::vector<std::vector<bool>> &visitedUnmarked,
         const std::vector<std::vector<Part>> &state
) {
    if (state[curI][curJ] == Part::UNMARKED) {
        if (!visitedUnmarked[curI][curJ]) {
            countDame++;
            visitedUnmarked[curI][curJ] = true;
        }
        return;
    }
    visited[curI][curJ] = true;
    if (curJ + 1 < size && !visited[curI][curJ + 1]) {
        dfs(curI, curJ + 1, size, countDame, visited, visitedUnmarked, state);
    }
    if (curI + 1 < size && !visited[curI + 1][curJ]) {
        dfs(curI + 1, curJ, size, countDame, visited, visitedUnmarked, state);
    }
    if (0 <= curJ - 1 && !visited[curI][curJ - 1]) {
        dfs(curI, curJ - 1, size, countDame, visited, visitedUnmarked, state);
    }
    if (0 <= curI - 1 && !visited[curI - 1][curJ]) {
        dfs(curI - 1, curJ, size, countDame, visited, visitedUnmarked, state);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<Part>> state(n, std::vector<Part>(n, Part::UNMARKED));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char color;
            scanf(" %c", &color);
            if (color == 'W') {
                visited[i][j] = true;
                state[i][j] = Part::WHITE;
            }
            if (color == 'B') {
                state[i][j] = Part::BLACK;
            }
        }
    }
    int countAtari = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::vector<std::vector<bool>> visitedUnmarked(n, std::vector<bool>(n, false));
            if (state[i][j] == Part::BLACK && !visited[i][j]) {
                int countDame = 0;
                dfs(i, j, n, countDame, visited, visitedUnmarked, state);
                if (countDame == 1) {
                    countAtari++;
                }
            }
        }
    }
    printf("%d", countAtari);
    return 0;
}