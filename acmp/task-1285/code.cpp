#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

const int UNDEF = -1;
const int N_LEVELS = 2;

enum State {
    VOID, BRIDGE, WALL
};

struct Coord {

    int level;

    int i;
 
    int j;
};

int bfs(Coord start,
        Coord end,
        int sizeI,
        int sizeJ,
        const std::vector<std::vector<State>> &field
) {
    std::vector<std::vector<std::vector<int>>> dist(N_LEVELS, std::vector<std::vector<int>>(sizeI, std::vector<int>(sizeJ, UNDEF)));
    std::queue<Coord> inProcess;
    for (int lvl = 0; lvl < N_LEVELS; lvl++) {
        inProcess.push({lvl, start.i, start.j});
        dist[lvl][start.i][start.j] = 0;
    }
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        if (cur.i == end.i && cur.j == end.j) {
            return dist[cur.level][cur.i][cur.j];
        }
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (!(cur.level == 0 && di != 0 && dj == 0 || 
                    cur.level == 1 && di == 0 && dj != 0)
                ) {
                    continue;
                }
                int newI = cur.i + di;
                int newJ = cur.j + dj;
                if (0 <= newI && newI < sizeI && 
                    0 <= newJ && newJ < sizeJ &&
                    field[newI][newJ] != State::WALL
                ) {
                    if (dist[cur.level][newI][newJ] == UNDEF) {
                        dist[cur.level][newI][newJ] = dist[cur.level][cur.i][cur.j] + 1;
                        inProcess.push({cur.level, newI, newJ});
                    }
                    if (field[newI][newJ] == State::VOID && 
                        dist[(cur.level + 1) % N_LEVELS][newI][newJ] == UNDEF
                    ) {
                        dist[(cur.level + 1) % N_LEVELS][newI][newJ] = dist[cur.level][cur.i][cur.j] + 1;
                        inProcess.push({(cur.level + 1) % N_LEVELS, newI, newJ});
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
    Coord start, end;
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
                start = {UNDEF, i, j};
            }
        }
    }
    printf("%d", bfs(start, end, sizeI, sizeJ, field));
    return 0;
}