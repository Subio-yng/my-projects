#include <stdio.h>
#include <vector>
  
// Time complexity: O(nV^2)
// Space complexity: O(nV^2)
  
int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::vector<bool>> edge(nV, std::vector<bool>(nV, false));
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        from--;
        to--;
        if (edge[from][to] || from == to) {
            printf("NO");
            return 0;
        }
        edge[from][to] = true;
    }
    for (int i = 0; i < nV; i++) {
        for (int j = i + 1; j < nV; j++) {
            if (edge[i][j] == edge[j][i]) {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}