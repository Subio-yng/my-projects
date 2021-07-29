#include <stdio.h>

// Time complexity: O(n^2)
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int a = 1; a < n; a++) {
        for (int b = a; b < n; b++) {
            if (n - a - b >= b << 1) {
                ans += (n - a - b >> 1) - b + 1;
            }
        }
    }
    printf("%d", ans);
    return 0;
}