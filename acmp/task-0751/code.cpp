#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    long long n;
    scanf("%lld", &n);
    if (n % 2 == 0) {
        printf("0 0");
    } else if (n % 2 == 1) {
        printf("2 %lld", n + 2);
    }
    return 0;
}
