#include <stdio.h>
#include <vector>
#include <algorithm>
 
// Time complexity: O(nV^3)
// Space complexity: O(nV^2) 
 
struct Cell {
 
    int val;
     
    int id;
};
 
int dfs(int curV, std::vector<bool> &visited, const std::vector<std::vector<bool>> &edges) {
    visited[curV] = true;
    int count = 0;
    for (int nextV = 0; nextV < (int) edges[curV].size(); nextV++) {
        if (!visited[nextV] && edges[curV][nextV]) {
            count += 1 + dfs(nextV, visited, edges);
        }
    }
    return count;
}
 
int topsort(const std::vector<std::vector<bool>> &edges) {
    int nV = (int) edges.size();
    std::vector<Cell> listComponents(nV);
    std::vector<bool> visited(nV, false);
    for (int i = 0; i < nV; i++) {
        listComponents[i].val = dfs(i, visited, edges);
        listComponents[i].id = i;
        visited = std::vector<bool>(nV, false);
    }
    std::sort(listComponents.rbegin(), listComponents.rend(), [](const Cell &left, const Cell &right) {
        return left.val < right.val;
    });
    int countComponents = 0;
    for (Cell v : listComponents) {
        if (!visited[v.id]) {
            dfs(v.id, visited, edges);
            countComponents++;
        }
    }
    return countComponents;
}
 
int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<std::vector<bool>> edges(nV, std::vector<bool>(nV, false));
    for (int from = 0; from < nV; from++) {
        for (int to = 0; to < nV; to++) {
            char e;
            scanf(" %c", &e);
            if (e == '1') {
                edges[from][to] = true;
            }
        }
    }
    printf("%d", topsort(edges));
    return 0;
}