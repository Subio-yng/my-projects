#include <stdio.h>
#include <vector>
  
// Time complexity: O(n^2)
// Space complexity: O(n^2)
 
void dfs(int curI, 
         int curJ, 
         int size, 
         int &countWall,
         std::vector<std::vector<bool>> &visited, 
         const std::vector<std::vector<bool>> &room
) {
    if (room[curI][curJ]) {
        countWall++;
        return;
    }
    visited[curI][curJ] = true;
    if (curJ <= size && !visited[curI][curJ + 1]) {
        dfs(curI, curJ + 1, size, countWall, visited, room);
    }
    if (curI <= size && !visited[curI + 1][curJ]) {
        dfs(curI + 1, curJ, size, countWall, visited, room);
    }
    if (0 <= curJ - 1 && !visited[curI][curJ - 1]) {
        dfs(curI, curJ - 1, size, countWall, visited, room);
    }
    if (0 <= curI - 1 && !visited[curI - 1][curJ]) {
        dfs(curI - 1, curJ, size, countWall, visited, room);
    }
}
 
int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<bool>> room(n + 2, std::vector<bool>(n + 2, true));
    std::vector<std::vector<bool>> visited(n + 2, std::vector<bool>(n + 2, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char wall;
            scanf(" %c", &wall);
            if (wall == '.') {
                room[i][j] = false;
            }
        }
    }
    int countWall = 0;
    dfs(1, 1, n, countWall, visited, room);
    if (!visited[n][n]) {
        dfs(n, n, n, countWall, visited, room);
    }
    printf("%d", (countWall - 4) * 25);
    return 0;
}