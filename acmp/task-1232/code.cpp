#include <stdio.h>
#include <vector>

// Time complexity: O(n * m)
// Space complexity: O(n * m)

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    std::vector<std::vector<int>> list(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            scanf("%d", &list[i][j]);
            sum += list[i][j];
        }
        printf("%d ", sum);
    }
    printf("\n");
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += list[i][j];
        }
        printf("%d ", sum);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < m; j++) {
            printf("%d ", list[i][j]);
        }
    }
    return 0;
}