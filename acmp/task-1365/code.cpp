#include <bits/stdc++.h>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

const int UNDEF = -1;

enum State {
    VOID,  FOREST, WATER
};

struct Coord {

    int i;

    int j;

    static Coord read() {
        int i, j;
        scanf("%d %d", &i, &j);
        return {i - 1, j - 1};
    }
};

int bfs(Coord start,
        Coord end,
        int sizeI,
        int sizeJ,
        std::vector<std::vector<State>> &field
) {
    std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
    std::queue<Coord> inProcess;
    inProcess.push(start);
    dist[start.i][start.j] = 0;
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        if (field[cur.i][cur.j] == State::FOREST) {
            dist[cur.i][cur.j]++;
            field[cur.i][cur.j] = State::VOID;
            inProcess.push(cur);
            continue;
        }
        if (cur.i == end.i && cur.j == end.j) {
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
                    field[newI][newJ] != State::WATER &&
                    dist[newI][newJ] == UNDEF
                ) {
                    dist[newI][newJ] = dist[cur.i][cur.j] + 1;
                    inProcess.push({newI, newJ});
                }
            }
        }
    }
    return dist[end.i][end.j];
}

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    Coord start = Coord::read();
    Coord end = Coord::read();
    std::vector<std::vector<State>> field(sizeI, std::vector<State>(sizeJ, State::VOID));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            char val;
            scanf(" %c", &val);
            if (val == 'W') {
                field[i][j] = State::FOREST;
            }
            if (val == '#') {
                field[i][j] = State::WATER;
            }
        }
    }
    field[start.i][start.j] = State::VOID;
    printf("%d", bfs(start, end, sizeI, sizeJ, field));
    return 0;
}
