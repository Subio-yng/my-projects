#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV^2)
// Space complexity: O(nV^2)

void dfs(int curV, int &count, std::vector<bool> &visited, const std::vector<std::vector<bool>> &edges) {
    visited[curV] = true;
    for (int nextV = 0; nextV < (int) edges.size(); nextV++) {
        if (edges[curV][nextV] && !visited[nextV]) {
            count++;
            dfs(nextV, count, visited, edges);
        }
    }
}

int main() {
    int nV, v0;
    scanf("%d %d", &nV, &v0);
    std::vector<std::vector<bool>> edges(nV, std::vector<bool>(nV, false));
    while (true) {
        int from;
        scanf("%d", &from);
        if (from == 0) {
            break;
        }
        int to;
        scanf("%d", &to);
        if (to == v0) {
            printf("NO");
            break;
        }
        edges[from - 1][to - 1] = true;
    }
    std::vector<bool> visited(nV, false);
    int count = 0;
    dfs(v0 - 1, count, visited, edges);
    if (count == nV - 1) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}