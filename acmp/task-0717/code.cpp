#include <stdio.h>
#include <vector>

// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)

long long dfs(int curV,
              const std::vector<int> &secV,
              std::vector<int> &orderV,
              std::vector<bool> &visited,
              const std::vector<std::vector<int>> &edges
) {
    long long curCost = secV[curV];
    visited[curV] = true;
    for (int nextV : edges[curV]) {
        if (!visited[nextV]) {
            curCost += dfs(nextV, secV, orderV, visited, edges);
        }
    }
    orderV.push_back(curV);
    return curCost;
}

int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<int> secV(nV);
    for (int i = 0; i < nV; i++) {
        scanf("%d", &secV[i]);
    }
    std::vector<std::vector<int>> edges(nV);
    for (int from = 0; from < nV; from++) {
        int nE;
        scanf("%d", &nE);
        for (int i = 0; i < nE; i++) {
            int to;
            scanf("%d", &to);
            edges[from].push_back(to - 1);
        }
    }
    std::vector<bool> visited(nV, false);
    std::vector<int> orderV;
    printf("%lld ", dfs(0, secV, orderV, visited, edges));
    printf("%d\n", orderV.size());
    for (int v : orderV) {
        printf("%d ", v + 1);
    }
    return 0;
}