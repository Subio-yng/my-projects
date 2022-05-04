#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV^3) 
// Space complexity: O(nV^2)
 
int main() {
    const int UNDEF = -1;
    int nV, start, end;
    scanf("%d %d %d", &nV, &start, &end);
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
                    (edges[from][to] == UNDEF || edges[from][to] > edges[from][cur] + edges[cur][to]) 
                ) {
                    edges[from][to] = edges[from][cur] + edges[cur][to];
                }
            }
        }
    }
    printf("%d", edges[start - 1][end - 1]);
    return 0;
}