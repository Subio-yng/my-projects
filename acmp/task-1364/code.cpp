#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
 
// Time complexity: O(1)
// Space complexity: O(1)

const int COUNT_STATE = 6;
const int START_POINT = -2;
const int UNDEF = -1;

struct Pair {

    int f;

    int s;

    Pair()
        : f(UNDEF)
        , s(UNDEF)
    {}

    Pair(int f, int s)
        : f(f)
        , s(s)
    {}

    bool operator <(const Pair &a) const {
        if (f == a.f) {
            return s < a.s;
        }
        return f < a.f;
    }

    bool isStartPoint() {
        return f == START_POINT;
    }

    bool isUndef() {
        return f == UNDEF;
    }
};

void printWay(std::map<Pair, Pair> &from, Pair end, Pair capacity) {
    if (!from[end].isStartPoint()) {
        printWay(from, from[end], capacity);
    } else {
        return;
    }
    if (end.f == capacity.f && from[end].s == end.s) {
        printf(">A\n");
    } else if (end.s == capacity.s && from[end].f == end.f) {
        printf(">B\n");
    } else if (end.f == 0 && from[end].s == end.s) {
        printf("A>\n");
    } else if (end.s == 0 && from[end].f == end.f) {
        printf("B>\n");
    } else if (end.s == capacity.s || end.f == 0) {
        printf("A>B\n");
    } else {
        printf("B>A\n");
    }
}

void bfs(Pair capacity, int end) {
    std::queue<Pair> inProcess;
    inProcess.push({0, 0});
    std::map<Pair, Pair> from;
    from[{0, 0}] = {START_POINT, START_POINT};
    std::vector<Pair> next(COUNT_STATE);
    while (!inProcess.empty()) {
        Pair cur = inProcess.front();
        if (cur.f == end || cur.s == end) {
            printWay(from, cur, capacity);
            return;
        }
        inProcess.pop();
        next[0] = {0, cur.s};
        next[1] = {cur.f, 0};
        next[2] = {capacity.f, cur.s};
        next[3] = {cur.f, capacity.s};
        next[4] = {cur.f - std::min(capacity.s - cur.s, cur.f), 
                   std::min(capacity.s, cur.f + cur.s)};
        next[5] = {std::min(capacity.f, cur.f + cur.s), 
                   cur.s - std::min(capacity.f - cur.f, cur.s)};
        for (Pair n : next) {
            if (from[n].isUndef()) {
                from[n] = cur;
                inProcess.push(n);
            }
        }
    }
    printf("Impossible");
}

int main() {
    int first, second, end;
    scanf("%d %d %d", &first, &second, &end);
    bfs({first, second}, end);
    return 0;
}