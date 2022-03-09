#include <stdio.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> list(n + 1);
    int edge = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char val;
            scanf(" %c", &val);
            if (val == '1') {
                list[i].push_back(j);
                edge++;
            }
        }
    }
    printf("%d %d", n, edge);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int) list[i].size(); j++) {
            printf("\n%d %d", i, list[i][j]);
        }
    }
    return 0;
}