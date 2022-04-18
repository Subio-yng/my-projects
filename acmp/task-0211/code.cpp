#include <stdio.h>
#include <vector>
#include <queue>
 
// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)
 
const int UNDEF = -1;
 
struct Coord {
     
    int i;
     
    int j;
     
    static Coord read() {
        int j, i;
        scanf("%d %d", &j, &i);
        return {i, j};
    }
};
 
int bfs(Coord start, 
        Coord end, 
        int sizeI, 
        int sizeJ, 
        const std::vector<std::vector<bool>> &state
) {
    std::vector<std::vector<int>> dist(sizeI + 2, std::vector<int>(sizeJ + 2, UNDEF));
    std::queue<Coord> inProcess;
    inProcess.push(start);
    dist[start.i][start.j] = 0;
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        if (cur.i == end.i && cur.j == end.j) {
            return dist[end.i][end.j];
        }
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di * di + dj * dj != 1) {
                    continue;
                }
                int newI = cur.i + di;
                int newJ = cur.j + dj;
                if (0 <= newI && newI <= sizeI + 1 &&
                    0 <= newJ && newJ <= sizeJ + 1 &&
                    dist[newI][newJ] == UNDEF &&
                    (state[newI][newJ] || newI == end.i && newJ == end.j) 
                ) {
                    dist[newI][newJ] = dist[cur.i][cur.j] + 1;
                    inProcess.push({newI, newJ});
                }
            }
        }
    }
    return 0;
}
 
int main() {
    int sizeJ, sizeI;
    scanf("%d %d", &sizeJ, &sizeI);
    std::vector<std::vector<bool>> state(sizeI + 2, std::vector<bool>(sizeJ + 2, true));
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            char val;
            scanf(" %c", &val);
            if (val == 'X') {
                state[i][j] = false;
            }
        }
    }
    while (true) {
        Coord start = Coord::read();
        Coord end = Coord::read();
        if (start.i == 0) {
            break;
        }
        printf("%d\n", bfs(start, end, sizeI, sizeJ, state));
    }
    return 0;
}