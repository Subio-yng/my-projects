#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV^2)
// Space complexity: O(nV^2)

void DFSway(std::vector<std::vector<bool>> &a, int v, int &count, std::vector<bool> &visited) {
    for (int i = 0; i < (int) a.size(); i++) {
        if (a[v][i] && visited[i]) {
            visited[i] = false;
            count++;
            DFSway(a, i, count, visited);
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
    std::vector<bool> visited(nV, true);
    visited[v0] = false;
    int count = 0;
    DFSway(edges, v0, count, visited);
    printf("%d", count);
    return 0;
}