#include <stdio.h>
#include <vector>
#include <algorithm>
 
// Time complexity: O(nV^3) 
// Space complexity: O(nV^2)

int main() {
    const int INF = 1'000'000 * 50 + 1;
    int nV;
    scanf("%d", &nV);
    std::vector<std::vector<int>> edges(nV, std::vector<int>(nV));
    for (int from = 0; from < nV; from++) {
        for (int to = 0; to < nV; to++) {
            scanf("%d", &edges[from][to]);
        }
    }
    for (int cur = 0; cur < nV; cur++) {
        for (int from = 0; from < nV; from++) {
            for (int to = 0; to < nV; to++) {
                edges[from][to] = std::min(edges[from][to], edges[from][cur] + edges[cur][to]);
            }
        }
    }
    int minDist = INF;
    for (int cur = 0; cur < nV; cur++) {
        for (int from = 0; from < nV; from++) {
            for (int to = 0; to < nV; to++) {
                if (edges[from][to] > edges[from][cur] + edges[cur][to]) {
                    printf("-1");
                    return 0;
                }
                if (from != to) {
                    minDist = std::min(minDist, edges[from][to]);
                }
            }
        }
    }
    printf("%d", minDist);
    return 0;
}