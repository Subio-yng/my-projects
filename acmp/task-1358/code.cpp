#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV^2)
// Space complexity: O(nV^2)
 
int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<bool>> edges(nV, std::vector<bool>(nV, false));
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from - 1][to - 1] = true;
    }
    for (int i = 0; i < nV; i++) {
        for (int j = i + 1; j < nV; j++) {
            if (!edges[i][j]) {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}