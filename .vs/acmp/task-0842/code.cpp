#include <stdio.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n;
    scanf("%lld", &n);
    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 5 == 0) {
        n /= 5;
    }
    if (n > 1) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}