#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    long long n;
    scanf("%lld", &n);
    const int UNDEF = -1;
    long long x = UNDEF, y = UNDEF;
    if (n > 1 && n % 2 == 1) {
        x = (n + 1) / 2;
        y = (n - 1) / 2;
    }
    if (n > 4 && n % 4 == 0) {
        x = n / 4 + 1;
        y = n / 4 - 1;
    }
    if (n == 0) {
        x = 1;
        y = 1;
    }
    if (x != UNDEF) {
        printf("Yes\n");
        printf("%lld %lld", x, y);
    } else {
        printf("No");
    }
    return 0;
}