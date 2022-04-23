#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
 
// Time complexity: O(sizeI * sizeJ * hp)
// Space complexity: O(sizeI * sizeJ * hp)
 
const int UNDEF = -1;
 
enum State {
    FLAME, ICE, WALL
};
 
struct Coord {
 
    int i;
 
    int j;
 
    int hp;
};
 
void bfs(Coord start,
        Coord end,
        State elem,
        int sizeI,
        int sizeJ,
        const std::vector<std::vector<int>> &power,
        const std::vector<std::vector<State>> &field
) {
    std::vector<std::vector<std::vector<int>>> dist(sizeI, std::vector<std::vector<int>>(sizeJ, std::vector<int>(start.hp + 1, UNDEF)));
    std::queue<Coord> inProcess;
    dist[start.i][start.j][start.hp] = 0;
    inProcess.push(start);
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        if (cur.i == end.i && cur.j == end.j) {
            printf("%d\n", dist[cur.i][cur.j][cur.hp]);
            return;
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
                    field[newI][newJ] != State::WALL
                ) {
                    int newHp = cur.hp;
                    if (field[newI][newJ] == elem) {
                        newHp += power[newI][newJ];
                    } else {
                        newHp -= power[newI][newJ];
                    }
                    newHp = std::min(newHp, start.hp);
                    if (newHp > 0 && dist[newI][newJ][newHp] == UNDEF) {
                        dist[newI][newJ][newHp] = dist[cur.i][cur.j][cur.hp] + 1;
                        inProcess.push({newI, newJ, newHp});
                    }
                }
            }
        }
        int newHp = cur.hp;
        if (field[cur.i][cur.j] == elem) {
            newHp += power[cur.i][cur.j];
        } else {
            newHp -= power[cur.i][cur.j];
        }
        newHp = std::min(newHp, start.hp);
        if (newHp > cur.hp && dist[cur.i][cur.j][newHp] == UNDEF) {
            dist[cur.i][cur.j][newHp] = dist[cur.i][cur.j][cur.hp] + 1;
            inProcess.push({cur.i, cur.j, newHp});
        }
    }
     printf("impossible\n");
}

int main() {
    int sizeI, sizeJ, hp;
    scanf("%d %d %d", &sizeI, &sizeJ, &hp);
    Coord start, end;
    std::vector<std::vector<State>> field(sizeI, std::vector<State>(sizeJ, State::FLAME));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            char val;
            scanf(" %c", &val);
            if (val == 'I') {
                field[i][j] = State::ICE;
            }
            if (val == 'X') {
                field[i][j] = State::WALL;
            }
            if (val == 'A') {
                start = {i, j, hp};
            }
            if (val == 'B') {
                end = {i, j, UNDEF};
            }
        }
    }
    std::vector<std::vector<int>> power(sizeI, std::vector<int>(sizeJ));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            scanf("%d", &power[i][j]);
        }
    }
    bfs(start, end, State::FLAME, sizeI, sizeJ, power, field);
    bfs(start, end, State::ICE, sizeI, sizeJ, power, field);
    return 0;
}