#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

const int COUNT_STATE = 6;
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

    bool isUndef() {
        return f == UNDEF;
    }
};

struct Next {

    Pair n;

    std::string ops;
};

void printWay(std::map<Pair, Next> &from,
              Pair end, 
              Pair capacity
) {
    if (end.f != 0 || end.s != 0) {
        printWay(from, from[end].n, capacity);
    } else {
        return;
    }
    printf("%s\n", from[end].ops.c_str());
}

void bfs(Pair capacity, int end) {
    std::vector<Pair> next(COUNT_STATE);
    std::vector<std::string> ops = {"A>", "B>", ">A", ">B", "A>B", "B>A"};
    std::queue<Pair> inProcess;
    inProcess.push({0, 0});
    std::map<Pair, Next> from;
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
        for (int i = 0; i < COUNT_STATE; i++) {
            if (from[next[i]].n.isUndef()) {
                from[next[i]] = {cur, ops[i]};
                inProcess.push(next[i]);
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