#include <stdio.h>
#include <vector>

// Time complexity: O(n * m)
// Space complexity: O(n * m)

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    std::vector<std::vector<int>> list(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &list[i][j]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            printf("%d ", list[i][j]);
        }
        printf("\n");
    }
    return 0;
}