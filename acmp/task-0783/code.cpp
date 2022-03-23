#include <stdio.h>
#include <vector>
 
// Time complexity: O(1)
// Space complexity: O(1)

void dfs(int curI, 
         int curJ, 
         int size, 
         std::vector<std::vector<bool>> &visited, 
         const std::vector<std::vector<bool>> &state
) {
    visited[curI][curJ] = true;
    if (curJ + 1 < size && !visited[curI][curJ + 1] && state[curI][curJ + 1] == !state[curI][curJ]) {
        dfs(curI, curJ + 1, size, visited, state);
    }
    if (curI + 1 < size && !visited[curI + 1][curJ] && state[curI + 1][curJ] == !state[curI][curJ]) {
        dfs(curI + 1, curJ, size, visited, state);
    }
    if (0 <= curJ - 1 && !visited[curI][curJ - 1] && state[curI][curJ - 1] == !state[curI][curJ]) {
        dfs(curI, curJ - 1, size, visited, state);
    }
    if (0 <= curI - 1 && !visited[curI - 1][curJ] && state[curI - 1][curJ] == !state[curI][curJ]) {
        dfs(curI - 1, curJ, size, visited, state);
    }
}

int main() {
    const int SIZE = 8;
    std::vector<std::vector<bool>> state(SIZE, std::vector<bool>(SIZE, false));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char color;
            scanf(" %c", &color);
            if (color == 'W') {
                state[i][j] = true;
            }
        }
    }
    std::vector<std::vector<bool>> visited(SIZE, std::vector<bool>(SIZE, false));
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!visited[i][j]) {
                dfs(i, j, SIZE, visited, state);
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}