#include <stdio.h>
#include <algorithm>

// Time complexity: O(n * sqrt(x))
// Space complexity: O(1)

bool isPowerNumber(int n) {
    for (int j = 2; j <= n / j; j++) {
        int temp = n;
        while (temp > 1 && temp % j == 0) {
            temp /= j;
        }
        if (temp == 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (isPowerNumber(x)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}