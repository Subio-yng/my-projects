#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O((sizeI * sizeJ)^2)
// Space complexity: O(sizeI * sizeJ)

struct Coord {

    int i;

    int j;
};

const int UNDEF = -1;

int bfs(int i,
        int j,
        const int sizeI,
        const int sizeJ,
        const int maxDist,
        const std::vector<std::vector<int>> &field
) {
    std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
    std::queue<Coord> inProcess;
    inProcess.push({i, j});
    dist[i][j] = 0;
    int sum = 0;
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        if (dist[cur.i][cur.j] > maxDist) {
            break;
        }
        if (field[cur.i][cur.j] > 0) {
            sum += std::max(0, field[cur.i][cur.j] - dist[cur.i][cur.j] + 1);
            continue;
        }
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di * di + dj * dj != 1) {
                    continue;
                }
                int nextI = cur.i + di;
                int nextJ = cur.j + dj;
                if (0 <= nextI && nextI < sizeI &&
                    0 <= nextJ && nextJ < sizeJ &&
                    field[nextI][nextJ] != UNDEF &&
                    dist[nextI][nextJ] == UNDEF
                ) {
                    dist[nextI][nextJ] = dist[cur.i][cur.j] + 1;
                    inProcess.push({nextI, nextJ});
                }
            }
        }
    }
    return sum;
}

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    int maxVal = 0;
    std::vector<std::vector<int>> field(sizeI, std::vector<int>(sizeJ));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            scanf("%d", &field[i][j]);
            maxVal = std::max(maxVal, field[i][j]);
        }
    }
    int maxSum = -1;
    int bestI = 0;
    int bestJ = 0;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            if (field[i][j] != 0) {
                continue;
            }
            int curSum = bfs(i, j, sizeI, sizeJ, maxVal, field);
            if (curSum > maxSum) {
                maxSum = curSum;
                bestI = i;
                bestJ = j;
            }
        }
    }
    printf("%d\n", maxSum);
    printf("%d %d", bestI + 1, bestJ + 1);
    return 0;
}