#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV^2)
// Space complexity: O(nV^2)
 
int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<char>> edges(nV + 1, std::vector<char>(nV + 1, '0'));
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from][to] = '1';
    }
    for (int i = 1; i <= nV; i++) {
        for (int j = i + 1; j <= nV; j++) {
            if (edges[i][j] == '0') {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}