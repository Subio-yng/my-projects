#include <stdio.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> list(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &list[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", list[j][i]);
        }
        printf("\n");
    }
    return 0;
}