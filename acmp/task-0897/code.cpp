#include <stdio.h>
#include <algorithm>

// Time complexity: O(n * sqrt(x))
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        bool ans = false;
        for (int j = 2; j <= x / j; j++) {
            for (int c = 2; pow(j, c) <= x; c++) {
                if (pow(j, c) == x) {
                    ans = true;
                    break;
                }
            }
        }
        if (ans) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}