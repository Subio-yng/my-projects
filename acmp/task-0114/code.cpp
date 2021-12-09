#include <stdio.h>

// Time complexity: O(k)
// Space complexity: O(1)

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int dp0 = k - 1;
    int dp1 = k * (k - 1);
    int dp2 = k * (k - 1);
    for (int i = 2; i < n; i++) {
        dp2 = (dp2 + dp0) * (k - 1);
        dp0 = dp1;
        dp1 = dp2;
    }
    printf("%d", dp2);
    return 0;
}