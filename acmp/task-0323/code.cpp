#include <stdio.h>

// Time complexity: O(n * sqrt(n))
// Space complexity: O(1)

bool simple(int n) {
    if (n % 2 == 0 && n != 2) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 2; i < n; i += 2) {
        if (simple(i) && simple(n - i)) {
            printf("%d %d", i, n - i);
            return 0;
        }
        if (i == 2) {
            i--;
        }
    }
    return 0;
}