#include <stdio.h>
#include <vector>
#include <queue>
 
// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)
 
struct Coord {
     
    int i;
     
    int j;
};
 
const int UNDEF = -1;
 
void bfs(Coord start, 
        int sizeI, 
        int sizeJ, 
        std::vector<std::vector<int>> &dist, 
        const std::vector<std::vector<bool>> &state
) {
    std::queue<Coord> inProcess;
    inProcess.push(start);
    dist[start.i][start.j] = 0;
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        for (int iMove = -1; iMove <= 1; iMove++) {
            for (int jMove = -1; jMove <= 1; jMove++) {
                if (iMove * iMove + jMove * jMove != 1) {
                    continue;
                }
                int newI = cur.i + iMove;
                int newJ = cur.j + jMove;
                if (0 <= newI && newI < sizeI &&
                    0 <= newJ && newJ < sizeJ &&
                    state[newI][newJ] &&
                    dist[newI][newJ] == UNDEF
                ) {
                    dist[newI][newJ] = dist[cur.i][cur.j] + 1;
                    inProcess.push({newI, newJ});
                }
            }
        }
    }
}
 
int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<bool>> state(sizeI, std::vector<bool>(sizeJ, true));
    Coord end;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            char val;
            scanf(" %c", &val);
            if (val == '*') {
                end = {i, j};
            }
            if (val == '1') {
                state[i][j] = false;
            }
        }
    }
    std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
    bfs(end, sizeI, sizeJ, dist, state);
    int nEnter;
    scanf("%d", &nEnter);
    int minDist = UNDEF;
    int idWay = UNDEF;
    for (int i = 1; i <= nEnter; i++) {
        int curI, curJ;
        scanf("%d %d", &curI, &curJ);
        curI--;
        curJ--;
        if (dist[curI][curJ] != UNDEF && 
            (minDist == UNDEF || minDist > dist[curI][curJ])
        ) {
            minDist = dist[curI][curJ];
            idWay = i;
        }
    }
    printf("%d", idWay);
    return 0;
}