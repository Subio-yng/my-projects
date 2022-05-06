#include <stdio.h>
#include <vector>
#include <algorithm>
 
// Time complexity: O(nV^3)
// Space complexity: O(nV^2)
 
int main() {
    const int UNDEF = -1;
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    int startV, endV;
    scanf("%d %d", &startV, &endV);
    std::vector<std::vector<double>> edges(nV, std::vector<double>(nV, UNDEF));
    for (int e = 0; e < nE; e++) {
        int from, to, dist;
        scanf("%d %d %d", &from, &to, &dist);
        edges[from - 1][to - 1] = dist / 100.0;
        edges[to - 1][from - 1] = dist / 100.0;
    }
    for (int cur = 0; cur < nV; cur++) {
        for (int from = 0; from < nV; from++) {
            for (int to = 0; to < nV; to++) {
                if (edges[from][cur] != UNDEF && edges[cur][to] != UNDEF &&
                    (edges[from][to] == UNDEF || edges[from][to] > 1 - ((1 - edges[from][cur]) * (1 - edges[cur][to]))) 
                ) {
                    edges[from][to] = 1 - ((1 - edges[from][cur]) * (1 - edges[cur][to]));
                }
            }
        }
    }
    printf("%.6f", edges[startV - 1][endV - 1]);
    return 0;
}