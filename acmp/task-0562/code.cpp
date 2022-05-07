#include <stdio.h>
#include <vector>
#include <algorithm>
 
// Time complexity: O(nV^3)
// Space complexity: O(nV^2)
 
int main() {
    const int UNDEF = 1'000'000;
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<int>> edges(nV, std::vector<int>(nV, UNDEF));
    for (int e = 0; e < nE; e++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from - 1][to - 1] = 0;
        edges[to - 1][from - 1] = std::min(edges[to - 1][from - 1], 1);
    }
    for (int cur = 0; cur < nV; cur++) {
        for (int from = 0; from < nV; from++) {
            for (int to = 0; to < nV; to++) {
                if (edges[from][cur] != UNDEF && edges[cur][to] != UNDEF &&
                    (edges[from][to] == UNDEF || edges[from][to] > edges[from][cur] + edges[cur][to]) 
                ) {
                    edges[from][to] = edges[from][cur] + edges[cur][to];
                }
            }
        }
    }
    int maxDist = 0;
    for (int from = 0; from < nV; from++) {
        for (int to = 0; to < nV; to++) {
            maxDist = std::max(maxDist, edges[from][to]);
        }
    }
    printf("%d", maxDist);
    return 0;
}