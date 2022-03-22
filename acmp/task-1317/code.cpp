#include <stdio.h>
#include <vector>
 
// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

void dfs(int curI, int curJ, std::vector<std::vector<bool>> &state) {
    state[curI][curJ] = false;
    if (curJ + 1 < (int) state[curI].size() && state[curI][curJ + 1]) {
        dfs(curI, curJ + 1, state);
    }
    if (curI + 1 < (int) state.size() && state[curI + 1][curJ]) {
        dfs(curI + 1, curJ, state);
    }
    if (curJ - 1 >= 0 && state[curI][curJ - 1]) {
        dfs(curI, curJ - 1, state);
    }
    if (curI - 1 >= 0 && state[curI - 1][curJ]) {
        dfs(curI - 1, curJ, state);
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
                dfs(i, j, state);
            }
        }
    }
    printf("%d", countComponents);
    return 0;
}