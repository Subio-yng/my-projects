#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

// Time complexity: O(sizeI * sizeJ * (maxIter + sizeI * sizeJ))
// Space complexity: O(sizeI * sizeJ)

struct Coord {

    int i;

    int j;
};

const int UNDEF = -1;

void bfs(Coord start, 
        int sizeI, 
        int sizeJ, 
        const int maxIter, 
        int &sum, 
        int &iter, 
        const std::vector<std::vector<int>> &field
) {
    std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
    std::queue<Coord> inProcess;
    inProcess.push(start);
    dist[start.i][start.j] = 1;
    int curSum = field[start.i][start.j];
    int curIter = 0;
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        if (curIter < dist[cur.i][cur.j]) {
            curIter++;
            if (curSum > sum) {
                sum = curSum;
                iter = dist[cur.i][cur.j];
            }
        }
        if (dist[cur.i][cur.j] == maxIter) {
            break;
        }
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di * di + dj * dj != 1) {
                    continue;
                }
                int newI = cur.i + di;
                int newJ = cur.j + dj;
                if (0 <= newI && newI < sizeI &&
                    0 <= newJ && newJ < sizeJ &&
                    dist[newI][newJ] == UNDEF
                ) {
                    curSum += field[newI][newJ];
                    dist[newI][newJ] = dist[cur.i][cur.j] + 1;
                    inProcess.push({newI, newJ});
                }
            }
        }
    }
}

int main() {
    const int INF = 1'000'000;
    int sizeI, sizeJ, maxIter;
    scanf("%d %d %d", &sizeI, &sizeJ, &maxIter);
    std::vector<std::vector<int>> field(sizeI, std::vector<int>(sizeJ));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            scanf("%d", &field[i][j]);
        }
    }
    int bestI = 0;
    int bestJ = 0;
    int bestSum = -INF;
    int bestIter = 0;
    for (int curI = 0; curI < sizeI; curI++) {
        for (int curJ = 0; curJ < sizeJ; curJ++) {
            int curSum = -INF;
            int curIter = 0;
            bfs({curI, curJ}, sizeI, sizeJ, maxIter, curSum, curIter, field);
            if (curSum > bestSum || curSum == bestSum && curIter < bestIter) {
                bestSum = curSum;
                bestIter = curIter;
                bestI = curI + 1;
                bestJ = curJ + 1;
            }
        }
    }
    printf("%d %d %d %d", bestI, bestJ, bestIter, bestSum);
    return 0;
}