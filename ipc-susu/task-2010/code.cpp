#include <stdio.h>
#include <queue>

// Time complexity: O(n * log(n))
// Space complexity: O(n * log(n))

struct Cell {

    int val;

    int div;

    double res;

    bool operator <(const Cell &a) const {
        if (res == a.res) {
            if (val == a.val) {
                return div < a.div;
            }
            return val < a.val;
        }
        return res < a.res;
    }
};

int main() {
    int n, diff;
    scanf("%d %d", &n, &diff);
    std::priority_queue<Cell> boards;
    double minLen = 1e9;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        boards.push({val, 1, 1.0 * val});
        minLen = std::min(minLen, 1.0 * val);
    }
    int cnt = 0;
    while (boards.top().res - minLen > diff) {
        Cell cur = boards.top();
        boards.pop();
        cur.div++;
        cur.res = 1.0 * cur.val / cur.div;
        minLen = std::min(minLen, cur.res);
        boards.push(cur);
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}