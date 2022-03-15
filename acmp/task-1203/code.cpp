#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV^2)
// Space complexity: O(nV^2)
 
int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<std::vector<bool>> edges(nV + 1, std::vector<bool>(nV + 1, false));
    for (int from = 1; from <= nV; from++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int to;
            scanf("%d", &to);
            edges[from][to] = true;
        }
    }
    printf("%d", nV);
    for (int from = 1; from <= nV; from++) {
        printf("\n");
        for (int to = 1; to <= nV; to++) {
            if (edges[from][to]) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
    }
    return 0;
}