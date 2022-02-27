#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>
 
// Time complexity: O(n * m)
// Space complexity: O(n)

struct Sock {

    int val;

    int cost;

    static Sock read() {
        int v, c;
        scanf("%d %d", &v, &c);
        return {v, c};
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    std::vector<Sock> list(m);
    for (int i = 0; i < m; i++) {
        list[i] = Sock::read();
    }
    std::vector<int> minCost(n + 1, INT_MAX);
    for (int curSum = 1; curSum <= n; curSum++) {
        for (int i = 0; i < m; i++) {
            if (list[i].val >= curSum) {
                minCost[curSum] = std::min(minCost[curSum], list[i].cost);
            } else {
                minCost[curSum] = std::min(minCost[curSum], minCost[curSum - list[i].val] + list[i].cost);
            }
        }
    }
    printf("%d", minCost[n]);
    return 0;
}