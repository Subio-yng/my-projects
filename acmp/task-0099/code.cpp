#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeZ * sizeI * sizeJ)
// Space complexity: O(sizeZ * sizeI * sizeJ)

const int UNDEF = -1;

struct Coord {

    int z;

    int i;

    int j;
};

int bfs(Coord start,
        Coord end,
        int sizeZ,
        int sizeI, 
        int sizeJ, 
        const std::vector<std::vector<std::vector<bool>>> &state
) {
    std::vector<std::vector<std::vector<int>>> dist(sizeZ, std::vector<std::vector<int>>(sizeI, std::vector<int>(sizeJ, UNDEF)));
    std::queue<Coord> inProcess;
    inProcess.push(start);
    dist[start.z][start.i][start.j] = 0;
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        if (cur.z == end.z && cur.i == end.i && cur.j == end.j) {
            return dist[cur.z][cur.i][cur.j];
        }
        for (int dz = 1; dz >= 0; dz--) {
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di * di + dj * dj + dz != 1) {
                        continue;
                    }
                    int newZ = cur.z + dz;
                    int newI = cur.i + di;
                    int newJ = cur.j + dj;
                    if (newZ < sizeZ &&
                        0 <= newI && newI < sizeI &&
                        0 <= newJ && newJ < sizeJ &&
                        state[newZ][newI][newJ] &&
                        dist[newZ][newI][newJ] == UNDEF
                    ) {
                        dist[newZ][newI][newJ] = dist[cur.z][cur.i][cur.j] + 1;
                        inProcess.push({newZ, newI, newJ});
                    }
                }
            }
        }
    }
    return UNDEF;
}

int main() {
    int sizeZ, sizeI, sizeJ;
    scanf("%d %d %d", &sizeZ, &sizeI, &sizeJ);
    std::vector<std::vector<std::vector<bool>>> state(sizeZ, std::vector<std::vector<bool>>(sizeI, std::vector<bool>(sizeJ, true)));
    Coord start;
    Coord end;
    for (int z = 0; z < sizeZ; z++) {
        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                char val;
                scanf(" %c", &val);
                if (val == 'o') {
                    state[z][i][j] = false;
                }
                if (val == '1') {
                    start = {z, i, j};
                }
                if (val == '2') {
                    end = {z, i, j};
                }
            }
        }
    }
    printf("%d", bfs(start, end, sizeZ, sizeI, sizeJ, state) * 5);
    return 0;
}