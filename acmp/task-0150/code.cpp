#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV^2)
// Space complexity: O(nV^2)

void dfs(int curV, int &count, std::vector<bool> &visited, const std::vector<std::vector<bool>> &edges) {
    for (int nextV = 0; nextV < (int) edges.size(); nextV++) {
        if (edges[curV][nextV] && !visited[nextV]) {
            visited[nextV] = true;
            count++;
            dfs(nextV, count, visited, edges);
        }
    }
}

int main() {
    int nV, v0;
    scanf("%d %d", &nV, &v0);
    v0--;
    std::vector<std::vector<bool>> edges(nV, std::vector<bool>(nV, false));
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            char val;
            scanf(" %c", &val);
            if (val == '1') {
                edges[i][j] = true;
            }
        }
    }
    std::vector<bool> visited(nV, false);
    visited[v0] = true;
    int count = 0;
    dfs(v0, count, visited, edges);
    printf("%d", count);
    return 0;
}