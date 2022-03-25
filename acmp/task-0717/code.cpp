#include <stdio.h>
#include <vector>

// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)

void dfs(int curV, std::vector<int> &listV, std::vector<bool> &visited, const std::vector<std::vector<int>> &edges) {
    visited[curV] = true;
    for (int nextV : edges[curV]) {
        if (!visited[nextV]) {
            dfs(nextV, listV, visited, edges);
        }
    }
    listV.push_back(curV);
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
        for (int j = 0; j < nE; j++) {
            int to;
            scanf("%d", &to);
            edges[from].push_back(to - 1);
        }
    }
    std::vector<bool> visited(nV, false);
    std::vector<int> listV;
    dfs(0, listV, visited, edges);
    long long cost = 0;
    for (int i = 0; i < (int) listV.size(); i++) {
        cost += secV[listV[i]];
    }
    printf("%lld %d\n", cost, (int) listV.size());
    for (int i = 0; i < (int) listV.size(); i++) {
        printf("%d ", listV[i] + 1);
    }
    return 0;
}