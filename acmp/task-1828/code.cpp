#include <bits/stdc++.h>

void solve() {
    long long n, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);
    a++;
    b++;
    long long cnt = (a / n) * (b / n) * n +
                    a % n * (b / n) +
                    b % n * (a / n) - 1;
    if (a % n != 0 && b % n != 0) {
        cnt += std::max(0LL, (a - 1) % n + (b - 1) % n - n + 1) + 1;
    }
    printf("%lld", cnt);
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