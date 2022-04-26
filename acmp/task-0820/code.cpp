#include <stdio.h>
#include <vector>
#include <queue>
 
// Time complexity: O(1)
// Space complexity: O(1)
 
const int SIZE = 4;
const int MAX = 1 << SIZE * SIZE;
const int UNDEF = -1;

void bfs(int start) {
    std::vector<int> dist(MAX + 1, UNDEF);
    std::queue<int> inProcess;
    dist[start] = 0;
    inProcess.push(start);
    while (!inProcess.empty()) {
        int cur = inProcess.front();
        inProcess.pop();
        if (cur == 0 || cur == MAX - 1) {
            printf("%d", dist[cur]);
            return;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int next = cur;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di * di + dj * dj > 1) {
                            continue;
                        }
                        int newI = i + di;
                        int newJ = j + dj;
                        if (0 <= newI && newI < SIZE && 0 <= newJ && newJ < SIZE) {
                            int pos = newI * SIZE + newJ;
                            next ^= 1 << pos;
                        }
                    }
                }
                if (dist[next] == UNDEF) {
                    dist[next] = dist[cur] + 1;
                    inProcess.push(next);
                }
            }
        }
    }
    printf("Impossible");
}

int main() {
    int start = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char val;
            scanf(" %c", &val);
            start <<= 1;
            if (val == 'w') {
                start += 0;
            } else if (val == 'b') {
                start++;
            } else {
                throw 1;
            }
        }
    }
    bfs(start);
    return 0;
}