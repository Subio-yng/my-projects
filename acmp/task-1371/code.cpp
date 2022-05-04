#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV^3) 
// Space complexity: O(nV^2)

int main() {
    const int UNDEF = 0;
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
                if (edges[from][cur] != UNDEF && edges[cur][to] != UNDEF &&
                    (edges[from][to] == UNDEF || edges[from][to] < edges[from][cur] + edges[cur][to])
                ) {
                    edges[from][to] = edges[from][cur] + edges[cur][to];
                }
            }
        }
    }
    for (int cur = 0; cur < nV; cur++) {
        for (int from = 0; from < nV; from++) {
            for (int to = 0; to < nV; to++) {
                if (edges[from][to] != UNDEF && edges[from][cur] != UNDEF && edges[cur][to] != UNDEF &&
                    edges[from][to] < edges[from][cur] + edges[cur][to]
                ) {
                    printf("Yes");
                    return 0;
                }
            }
        }
    }
    printf("No");
    return 0;
}