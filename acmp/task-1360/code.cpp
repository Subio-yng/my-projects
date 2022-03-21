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
    for (int nextV : edges[curV]) {
        if (!visited[nextV]) {
            dfs(nextV, list, visited, edges);
        }
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
    std::vector<int> component;
    int countComponents = 0;
    for (int i = 0; i < nV; i++) {
        if (!visited[i]) {
            dfs(i, component, visited, edges);
            countComponents++;
        }
        component.clear();
    }
    printf("%d\n", countComponents);
    visited = std::vector<bool>(nV, false);
    for (int i = 0; i < nV; i++) {
        if (!visited[i]) {
            dfs(i, component, visited, edges);
            printf("%d\n", (int) component.size());
            for (int j = 0; j < (int) component.size(); j++) {
                printf("%d ", component[j] + 1);
            }
            component.clear();
            printf("\n");
        }
    }
    return 0;
}