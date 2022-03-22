#include <stdio.h>
#include <vector>
 
// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

void dfs(int curI, int curJ, int sizeI, int sizeJ, std::vector<std::vector<bool>> &state) {
    state[curI][curJ] = false;
    if (curJ + 1 < sizeJ && state[curI][curJ + 1]) {
        dfs(curI, curJ + 1, sizeI, sizeJ, state);
    }
    if (curI + 1 < sizeI && state[curI + 1][curJ]) {
        dfs(curI + 1, curJ, sizeI, sizeJ, state);
    }
    if (0 <= curJ - 1 && state[curI][curJ - 1]) {
        dfs(curI, curJ - 1, sizeI, sizeJ, state);
    }
    if (0 <= curI - 1 && state[curI - 1][curJ]) {
        dfs(curI - 1, curJ, sizeI, sizeJ, state);
    }
}

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<bool>> state(sizeI, std::vector<bool>(sizeJ, false));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            char curState;
            scanf(" %c", &curState);
            if (curState == '#') {
                state[i][j] = true;
            }
        }
    }
    int countComponents = 0;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            if (state[i][j]) {
                countComponents++;
                dfs(i, j, sizeI, sizeJ, state);
            }
        }
    }
    printf("%d", countComponents);
    return 0;
}