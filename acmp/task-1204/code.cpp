#include <stdio.h>
#include <vector>
  
// Time complexity: O(nV^2)
// Space complexity: O(nV^2)
  
int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<std::vector<char>> edges(nV, std::vector<char>(nV));
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            scanf(" %c", &edges[i][j]);
        }
        if (edges[i][i] == '1') {
            printf("NO");
            return 0;
        }
    }
    for (int i = 0; i < nV; i++) {
        for (int j = i; j < nV; j++) {
            if (edges[i][j] != edges[j][i]) {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}