#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

const int UNDEF = -1;

struct Coord {
 
    int i;
 
    int j;
};

int bfs(Coord start, 
        Coord end, 
        int sizeI,
        int sizeJ,
        const std::vector<std::vector<bool>> &state
) {
    std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
    std::queue<Coord> inProcess;
    inProcess.push(start);
    dist[start.i][start.j] = 0;
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        if (cur.i == end.i && cur.j == end.j) {
            return dist[cur.i][cur.j];
        }
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di * di + dj * dj != 1) {
                    continue;
                }
                int newI = cur.i + di;
                int newJ = cur.j + dj;
                while (0 <= newI && newI < sizeI && 0 <= newJ && newJ < sizeJ) {
                    if (state[newI][newJ] &&
                        (dist[newI][newJ] == UNDEF || 
                        dist[newI][newJ] > dist[cur.i][cur.j] + 1)
                    ) {
                        dist[newI][newJ] = dist[cur.i][cur.j] + 1;
                        inProcess.push({newI, newJ});
                    } else {
                        break;
                    }
                    newI += di;
                    newJ += dj;
                }
            }
        }
    }
    return UNDEF;
}
 
int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<bool>> state(sizeI, std::vector<bool>(sizeJ, true));
    Coord start;
    Coord end;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            char val;
            scanf(" %c", &val);
            if (val == 'P') {
                state[i][j] = false;
            }
            if (val == 'S') {
                start = {i, j};
            }
            if (val == 'F') {
                end = {i, j};
            }
        }
    }
    printf("%d", bfs(start, end, sizeI, sizeJ, state));
    return 0;
}