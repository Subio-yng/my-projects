#include <stdio.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

int main() {
    int n;
    scanf("%d", &n);
    n--;
    std::vector<std::vector<long long>> honeycomb(2 * n + 1, std::vector<long long>(2 * n + 1, 0));
    for (int i = 0; i <= n; i++) {
        honeycomb[0][i] = 1;
        honeycomb[i][0] = 1;
    }
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            if (honeycomb[i - 1][j - 1] != 0) {
                honeycomb[i][j] += honeycomb[i - 1][j - 1] + honeycomb[i][j - 1] + honeycomb[i - 1][j];
            }
        }
    }
    printf("%lld", honeycomb[2 * n][2 * n]);
    return 0;
}