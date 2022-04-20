#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

const int UNDEF = -1;
const int SIZE_Z = 4;

struct Coord {

    int z;

    int i;

    int j;
};

int bfs(Coord start,
        Coord end,
        int sizeI,
        int sizeJ,
        const std::vector<std::vector<bool>> &state
) {
    std::vector<std::vector<std::vector<int>>> dist(SIZE_Z, std::vector<std::vector<int>>(sizeI, std::vector<int>(sizeJ, UNDEF)));
    std::queue<Coord> inProcess;
    for (int z = 0; z < SIZE_Z; z++) {
        dist[z][start.i][start.j] = 0;
        inProcess.push({z, start.i, start.j});
    }
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        if (cur.i == end.i && cur.j == end.j) {
            return dist[cur.z][cur.i][cur.j];
        }
        for (int dz = 0; dz <= 1; dz++) {
            int newZ = (cur.z + dz) % SIZE_Z;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (newZ == 0 && (di != 0 || dj != 1) ||
                        newZ == 1 && (di != 1 || dj != 0) ||
                        newZ == 2 && (di != 0 || dj != -1) ||
                        newZ == 3 && (di != -1 || dj != 0)
                    ) {
                        continue;
                    }
                    int newI = cur.i + di;
                    int newJ = cur.j + dj;
                    if (0 <= newI && newI < sizeI &&
                        0 <= newJ && newJ < sizeJ &&
                        state[newI][newJ] && dist[newZ][newI][newJ] == UNDEF
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
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<bool>> state(sizeI, std::vector<bool>(sizeJ, true));
    Coord start, end;
    for (int i = 0; i < sizeI; i++) {
        scanf("\n");
        for (int j = 0; j < sizeJ; j++) {
            char val;
            scanf("%c", &val);
            if (val == 'X') {
                state[i][j] = false;
            }
            if (val == 'S') {
                start = {UNDEF, i, j};
            }
            if (val == 'F') {
                end = {UNDEF, i, j};
            }
        }
    }
    printf("%d", bfs(start, end, sizeI, sizeJ, state));
    return 0;
}