#include <stdio.h>
#include <vector>
#include <random>

// Space complexity: O(sizeI * sizeJ)

struct Coord {
  
    int i;
  
    int j;
};

std::vector<Coord> MOVE = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void dfs(int curI,
         int curJ,
         int sizeI,
         int sizeJ,
         int move, 
         bool &foundWay,
         std::vector<std::vector<short>> &state, 
         std::vector<std::vector<int>> &way
) {
    way[curI][curJ] = move;
    if (move == sizeI * sizeJ) {
        foundWay = true;
        return;
    }
    int minMoves = 9;
    int nextI = -1;
    int nextJ = -1;
    for (int iDir = 0; iDir < 8; iDir++) {
        int newI = curI + MOVE[iDir].i;
        int newJ = curJ + MOVE[iDir].j;
        if (0 <= newI && newI < sizeI && 0 <= newJ && newJ < sizeJ) {
            if (state[newI][newJ] < minMoves && way[newI][newJ] == 0) {
                minMoves = state[newI][newJ];
                nextI = newI;
                nextJ = newJ;
            }
            state[newI][newJ]--;
        }
    }
    if (nextI != -1) {
        dfs(nextI, nextJ, sizeI, sizeJ, move + 1, foundWay, state, way);
    }
}

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    int curI = 0;
    int curJ = 0;
    std::vector<std::vector<short>> state(sizeI, std::vector<short>(sizeJ, 0));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            char val;
            scanf(" %c", &val);
            if (val == 'K') {
                curI = i;
                curJ = j;
            }
            for (int m = 0; m < 8; m++) {
                int newI = i + MOVE[m].i;
                int newJ = j + MOVE[m].j;
                if (0 <= newI && newI < sizeI && 0 <= newJ && newJ < sizeJ) {
                    state[i][j]++;
                }
            }
        }
    }
    std::vector<std::vector<int>> way(sizeI, std::vector<int>(sizeJ, 0));
    std::vector<std::vector<short>> curState = state;
    bool foundWay = false;
    std::random_device rd;
    std::mt19937 gen(rd());
    while (!foundWay) {
        std::shuffle(MOVE.begin(), MOVE.end(), gen);
        way.assign(sizeI, std::vector<int>(sizeJ, 0));
        curState = state;
        dfs(curI, curJ, sizeI, sizeJ, 1, foundWay, curState, way);
    }
    int countMove = sizeI * sizeJ;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            if (countMove > 9 && way[i][j] < 10) {
                printf(" ");
            }
            if (countMove > 99 && way[i][j] < 100) {
                printf(" ");
            }
            if (countMove > 999 && way[i][j] < 1000) {
                printf(" ");
            }
            if (countMove > 9999 && way[i][j] < 10000) {
                printf(" ");
            }
            printf("%d ", way[i][j]);
        }
        printf("\n");
    }
    return 0;
}