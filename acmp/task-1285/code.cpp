#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

const int UNDEF = -1;
const int SIZE_Z = 2;

enum State {
    VOID, BRIDGE, WALL
};

struct Coord {

    int z;

    int i;
 
    int j;
};

int bfs(Coord start1,
        Coord start2,
        Coord end,
        int sizeI,
        int sizeJ,
        const std::vector<std::vector<State>> &field
) {
    std::vector<std::vector<std::vector<int>>> dist(SIZE_Z, std::vector<std::vector<int>>(sizeI, std::vector<int>(sizeJ, UNDEF)));
    std::queue<Coord> inProcess;
    inProcess.push(start1);
    inProcess.push(start2);
    dist[start1.z][start1.i][start1.j] = 0;
    dist[start2.z][start1.i][start1.j] = 0;
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        if (cur.i == end.i && cur.j == end.j) {
            return dist[cur.z][cur.i][cur.j];
        }
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (!(cur.z == 0 && di != 0 && dj == 0 || 
                    cur.z == 1 && di == 0 && dj != 0)
                ) {
                    continue;
                }
                int newI = cur.i + di;
                int newJ = cur.j + dj;
                if (0 <= newI && newI < sizeI && 
                    0 <= newJ && newJ < sizeJ &&
                    field[newI][newJ] != State::WALL
                ) {
                    if (dist[cur.z][newI][newJ] == UNDEF) {
                        dist[cur.z][newI][newJ] = dist[cur.z][cur.i][cur.j] + 1;
                        inProcess.push({cur.z, newI, newJ});
                    }
                    if (field[newI][newJ] == State::VOID && 
                        dist[(cur.z + 1) % SIZE_Z][newI][newJ] == UNDEF
                    ) {
                        dist[(cur.z + 1) % SIZE_Z][newI][newJ] = dist[cur.z][cur.i][cur.j] + 1;
                        inProcess.push({(cur.z + 1) % SIZE_Z, newI, newJ});
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
    std::vector<std::vector<State>> field(sizeI, std::vector<State>(sizeJ, State::VOID));
    Coord start1, start2;
    Coord end;
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            char val;
            scanf(" %c", &val);
            if (val == '#') {
                field[i][j] = State::WALL;
            }
            if (val == 'B') {
                field[i][j] = State::BRIDGE;
            }
            if (val == 'E') {
                end = {UNDEF, i, j};
            }
            if (val == 'S') {
                start1 = {0, i, j};
                start2 = {1, i, j};
            }
        }
    }
    printf("%d", bfs(start1, start2, end, sizeI, sizeJ, field));
    return 0;
}