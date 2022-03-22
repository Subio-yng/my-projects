#include <stdio.h>
#include <vector>
#include <set>
 
// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)

void dfs(int curV, 
         std::vector<int> &curTowns, 
         std::vector<bool> &visited, 
         const std::vector<std::set<int>> &edges
) {
    visited[curV] = true;
    curTowns.push_back(curV);
    for (int nextV : edges[curV]) {
        if (!visited[nextV]) {
            dfs(nextV, curTowns, visited, edges);
        }
    }
}

int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::set<int>> edges(nV);
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from - 1].insert(to - 1);
        edges[to - 1].insert(from - 1);
    }
    int nCap;
    scanf("%d", &nCap);
    std::vector<bool> visited(nV, false);
    std::vector<int> listCap(nCap);
    for (int i = 0; i < nCap; i++) {
        scanf("%d", &listCap[i]);
        listCap[i]--;
        visited[listCap[i]] = true;
    }
    std::vector<std::vector<int>> towns(nCap);
    for (int i = 0; i < nCap; i++) {
        dfs(listCap[i], towns[i], visited, edges);
    }
    for (int i = 0; i < nCap; i++) {
        printf("%d\n", (int) towns[i].size());
        for (int j = 0; j < (int) towns[i].size(); j++) {
            printf("%d ", towns[i][j] + 1);
        }
        printf("\n");
    }
    return 0;
}