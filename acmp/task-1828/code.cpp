#include <bits/stdc++.h>

// Time complexity: O(t)
// Space complexity: O(1)

void solve() {
    long long n, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);
    printf("%lld", (a / n) * (b / n) * n +
                   (a % n + 1) * (b / n) +
                   (b % n + 1) * (a / n) +
                   std::max(0LL, a % n + b % n - n + 1));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        solve();
        printf("\n");
        t--;
    }
    return 0;
}