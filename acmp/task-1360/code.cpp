#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)
 
void dfs(int curV,
         std::vector<int> &list,
         std::vector<bool> &visited,
         const std::vector<std::vector<int>> &edges
) {
    visited[curV] = true;
    list.push_back(curV);
    for (int v : edges[curV]) {
        if (visited[v]) {
            continue;
        }
        dfs(v, list, visited, edges);
    }
}
 
int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<int>> edges(nV);
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from - 1].push_back(to - 1);
        edges[to - 1].push_back(from - 1);
    }
    std::vector<bool> visited(nV, false);
    std::vector<int> list;
    int count = 0;
    for (int i = 0; i < nV; i++) {
        if (!visited[i]) {
            dfs(i, list, visited, edges);
            count++;
        }
        list.clear();
    }
    printf("%d", count);
    visited = std::vector<bool>(nV, false);
    for (int i = 0; i < nV; i++) {
        if (!visited[i]) {
            dfs(i, list, visited, edges);
            printf("\n%d\n", (int) list.size());
            for (int j = 0; j < (int) list.size(); j++) {
                printf("%d ", list[j] + 1);
            }
            list.clear();
        }
    }
    return 0;
}