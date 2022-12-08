#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    long long n;
    scanf("%lld", &n);
    if (n > 1 && n % 2 == 1) {
        printf("Yes\n");
        printf("%lld %lld", (n + 1) / 2, (n - 1) / 2);
    } else if (n > 4 && n % 4 == 0) {
        printf("Yes\n");
        printf("%lld %lld", n / 4 + 1, n / 4 - 1);
    } else if (n == 0) {
        printf("Yes\n");
        printf("1 1");
    } else {
        printf("No");
    }
    return 0;
}