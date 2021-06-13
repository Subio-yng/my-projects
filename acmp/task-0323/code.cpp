#include <stdio.h>

// Time complexity: O(n * sqrt(n))
// Space complexity: O(1)

bool simple(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 2; i < n; i++) {
        if (simple(i) && simple(n - i)) {
            printf("%d %d", i, n - i);
            return 0;
        }
    }
    return 0;
}