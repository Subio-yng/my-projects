#include <bits/stdc++.h>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> field(n, std::vector<int>(n));
    int cur = 1;
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i; j++) {
            field[i][j] = cur;
            cur++;
        }
        for (int j = i + 1; j < n - i; j++) {
            field[j][n - i - 1] = cur;
            cur++;
        }
        for (int j = n - i - 2; j >= i; j--) {
            field[n - i - 1][j] = cur;
            cur++;
        }
        for (int j = n - i - 2; j > i; j--) {
            field[j][i] = cur;
            cur++;
        }
    }
    if (n % 2 == 1) {
        field[n / 2][n / 2] = cur;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }
    return 0;
}