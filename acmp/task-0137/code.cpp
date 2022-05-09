#include <stdio.h>
#include <vector>
#include <algorithm>
  
// Time complexity: O(nV^3)
// Space complexity: O(nV^2)
  
int main() {
    const int INF = 1000 * 1000 * 1000;
    int nV;
    scanf("%d", &nV);
    std::vector<std::vector<int>> edges(nV, std::vector<int>(nV));
    for (int from = 0; from < nV; from++) {
        for (int to = 0; to < nV; to++) {
            scanf("%d", &edges[from][to]);
            if (edges[from][to] == 0) {
                edges[from][to] = INF;
            }
        }
    }
    for (int cur = 0; cur < nV; cur++) {
        for (int from = 0; from < nV; from++) {
            for (int to = 0; to < nV; to++) {
                if (edges[from][cur] < INF && edges[cur][to] < INF) {
                    edges[from][to] = std::min(edges[from][to], std::max(-INF, edges[from][cur] + edges[cur][to]));
                }
            }
        }
    }
    for (int from = 0; from < nV; from++) {
        for (int to = 0; to < nV; to++) {
            for (int cur = 0; cur < nV; cur++) {
                if (edges[from][cur] < INF && edges[cur][to] < INF && edges[cur][cur] < 0) {
                    edges[from][to] = -INF;
                }
            }
        }
    }
    for (int from = 0; from < nV; from++) {
        for (int to = 0; to < nV; to++) {
            if (edges[from][to] == INF && from != to) {
                printf("0 ");
            } else if (edges[from][to] == -INF) {
                printf("2 ");
            } else {
                printf("1 ");
            }
        }
        printf("\n");
    }
    return 0;
}