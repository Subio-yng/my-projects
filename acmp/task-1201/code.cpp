#include <stdio.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<std::vector<int>> list(nV + 1);
    int nE = 0;
    for (int i = 1; i <= nV; i++) {
        for (int j = 1; j <= nV; j++) {
            char val;
            scanf(" %c", &val);
            if (val == '1') {
                list[i].push_back(j);
                nE++;
            }
        }
    }
    printf("%d %d", nV, nE);
    for (int i = 1; i <= nV; i++) {
        for (int j = 0; j < (int) list[i].size(); j++) {
            printf("\n%d %d", i, list[i][j]);
        }
    }
    return 0;
}