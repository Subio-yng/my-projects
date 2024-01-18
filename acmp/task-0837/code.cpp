#include <bits/stdc++.h>

// Time complexity: O(t)
// Space complexity: O(1)

void solve() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    if (m <= (n - 1) * (n - 2) / 2 && n != 1) {
        printf("Yes");
    } else {
        printf("No");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
        printf("\n");
    }
    return 0;
}