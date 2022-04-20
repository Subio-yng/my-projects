#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

const int UNDEF = -1;

enum State {
    VOID, WALL, EXIT
};

struct Coord {
 
    int i;
 
    int j;
};

int bfs(Coord start, 
        int sizeI, 
        int sizeJ, 
        const std::vector<std::vector<State>> &field
) {
    std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
    std::queue<Coord> inProcess;
    inProcess.push(start);
    dist[start.i][start.j] = 0;
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        if (field[cur.i][cur.j] == State::EXIT) {
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
                    if (field[newI][newJ] == State::WALL) {
                        break;
                    }
                    newI += di;
                    newJ += dj;
                    if (field[newI - di][newJ - dj] == State::EXIT) {
                        break;
                    }
                }
                newI -= di;
                newJ -= dj;
                if (dist[newI][newJ] == UNDEF) {
                    dist[newI][newJ] = dist[cur.i][cur.j] + 1;
                    inProcess.push({newI, newJ});
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
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            char val;
            scanf(" %c", &val);
            if (val == '2') {
                field[i][j] = State::EXIT;
            }
            if (val == '1') {
                field[i][j] = State::WALL;
            }
        }
    }
    printf("%d", bfs({0, 0}, sizeI, sizeJ, field));
    return 0;
}