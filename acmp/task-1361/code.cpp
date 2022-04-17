#include <stdio.h>
#include <vector>
#include <queue>
 
// Time complexity: O(1)
// Space complexity: O(1)
 
const int SIZE = 1000;
const int COUNT_STATE = 4;
const int UNDEF = -1;
const int START_POINT = 0;

void printWay(const std::vector<int> &from, int last) {
    if (from[last] != START_POINT) {
        printWay(from, from[last]);
    }
    printf("%d\n", last);
}

void bfs(int start, int end) {
    std::vector<int> next(COUNT_STATE);
    std::vector<int> from(SIZE * 10, UNDEF);
    std::queue<int> inProcess;
    inProcess.push(start);
    from[start] = START_POINT;
    while (!inProcess.empty()) {
        int cur = inProcess.front();
        inProcess.pop();
        next[0] = cur + SIZE;
        next[1] = cur - 1;
        next[2] = cur % 10 * SIZE + cur / 10;
        next[3] = cur % SIZE * 10 + cur / SIZE;
        for (int n : next) {
            if (n % 10 != 0 && n < SIZE * 10 && from[n] == UNDEF) {
                from[n] = cur;
                inProcess.push(n);
            }
        }
    }
    printWay(from, end);
}
 
int main() {
    int start, end;
    scanf("%d %d", &start, &end);
    bfs(start, end);
    return 0;
}