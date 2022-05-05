#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV^3)
// Space complexity: O(nV^2)
 
int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<std::vector<bool>> edges(nV, std::vector<bool>(nV));
    for (int from = 0; from < nV; from++) {
        for (int to = 0; to < nV; to++) {
            char val;
            scanf(" %c", &val);
            edges[from][to] = val == '1';
        }
    }
    for (int cur = 0; cur < nV; cur++) {
        for (int from = 0; from < nV; from++) {
            for (int to = 0; to < nV; to++) {
                if (edges[from][cur] && edges[cur][to]) {
                    edges[from][to] = true;
                }
            }
        }
    }
    for (int from = 0; from < nV; from++) {
        for (int to = 0; to < nV; to++) {
            if (edges[from][to]) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}