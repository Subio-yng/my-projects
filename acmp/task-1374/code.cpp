#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV^3) 
// Space complexity: O(nV^2)

int main() {
    const int UNDEF = -1;
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<int>> edges(nV, std::vector<int>(nV, UNDEF));
    for (int e = 0; e < nE; e++) {
        int from, to, length;
        scanf("%d %d %d", &from, &to, &length);
        edges[from - 1][to - 1] = length;
        edges[to - 1][from - 1] = length;
    }
    for (int cur = 0; cur < nV; cur++) {
        for (int from = 0; from < nV; from++) {
            for (int to = 0; to < nV; to++) {
                if (from == to) {
                    continue;
                }
                if (edges[from][cur] != UNDEF && edges[cur][to] != UNDEF &&
                    (edges[from][to] == UNDEF || edges[from][to] > edges[from][cur] + edges[cur][to]) 
                ) {
                    edges[from][to] = edges[from][cur] + edges[cur][to];
                }
            }
        }
    }
    int minDist = UNDEF;
    int idFrom = UNDEF;
    for (int from = 0; from < nV; from++) {
        int maxDist = UNDEF;
        for (int to = 0; to < nV; to++) {
            maxDist = std::max(maxDist, edges[from][to]);
        }
        if (minDist == UNDEF || minDist > maxDist) {
            minDist = maxDist;
            idFrom = from;
        }
    }
    printf("%d", idFrom + 1);
    return 0;
}