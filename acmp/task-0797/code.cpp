#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
 
// Time complexity: O(2^size * n^2)
// Space complexity: O(2^size)

const int SIZE = 50;
const int UNDEF = -1;

struct Coord {

    int x;

    int y;

    int code;
};

int getCode(int x, int y, int size, const std::vector<int> &minX, const std::vector<int> &maxX) {
    int code = 0;
    for (int dy = 0; dy < size; dy++) {
        if (maxX[y + dy] == 0) {
            code |= 3 << (dy * 2);
        } else {
            if (x <= minX[y + dy] && minX[y + dy] < size + x) {
                code |= 1 << (dy * 2);
            } 
            if (x <= maxX[y + dy] && maxX[y + dy] < size + x) {
                code |= 2 << (dy * 2);
            }
        }
    }
    return code;
}

void bfs(Coord start, int endY, int size, const std::vector<int> &minX, const std::vector<int> &maxX) {
    std::vector<std::vector<std::vector<int>>> dist(SIZE - size + 2, std::vector<std::vector<int>>(SIZE - size + 2, std::vector<int>(1 << (size * 2), UNDEF)));
    std::queue<Coord> inProcces;
    dist[start.x][start.y][start.code] = 0;
    inProcces.push(start);
    while (!inProcces.empty()) {
        Coord cur = inProcces.front();
        inProcces.pop();
        if (cur.y >= endY + 1 - size && cur.code == (1 << (size << 1)) - 1) {
            printf("%d", dist[cur.x][cur.y][cur.code]);
            return;
        }
        for (int dy = 0; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dy * dy + dx * dx != 1) {
                    continue;
                }
                int newX = cur.x + dx;
                int newY = cur.y + dy;
                int newCode = cur.code;
                if (dy == 1) {
                    newCode >>= 2;
                }
                if (1 <= newX && newX <= SIZE - size + 1 && 
                    newY <= SIZE - size + 1 &&
                    (dy != 1 || (cur.code & 3) == 3)
                ) {
                    newCode |= getCode(newX, newY, size, minX, maxX);
                    if (dist[newX][newY][newCode] == UNDEF) {
                        dist[newX][newY][newCode] = dist[cur.x][cur.y][cur.code] + 1;
                        inProcces.push({newX, newY, newCode});
                    }
                }
            }
        }
    }
    throw 1;
}

int main() {
    int n, size;
    scanf("%d %d", &n, &size);
    std::vector<int> minX(SIZE + 1, SIZE + 1);
    std::vector<int> maxX(SIZE + 1, 0);
    int endY = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        minX[y] = std::min(minX[y], x);
        maxX[y] = std::max(maxX[y], x);
        endY = std::max(endY, y);
    }
    bfs({1, 1, getCode(1, 1, size, minX, maxX)}, endY, size, minX, maxX);
    return 0;
}