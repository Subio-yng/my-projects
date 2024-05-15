#include <bits/stdc++.h>

// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)

int dfs(int curV, std::vector<bool> &visited, const std::vector<std::vector<int>> &edges) {
    visited[curV] = true;
    int cntOdd = 0;
    if ((int) edges[curV].size() % 2 == 1) {
        cntOdd = 1;
    }
    for (int nextV : edges[curV]) {
        if (!visited[nextV]) {
            cntOdd += dfs(nextV, visited, edges);
        }
    }
    return cntOdd;
}

int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<int>> edges(nV);
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        from--;
        to--;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    int cnt = 0;
    std::vector<bool> visited(nV, false);
    for (int v = 0; v < nV; v++) {
        if (!visited[v] && !edges[v].empty()) {
            cnt += (std::max(2, dfs(v, visited, edges)) + 1) / 2;
        }
    }
    printf("%d", cnt);
    return 0;
}