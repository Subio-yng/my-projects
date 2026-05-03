#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    long long multD = 0;
    long long sumN = 0;
    for (int i = 0; i < n; i++) {
        long long curN;
        scanf("%lld", &curN);
        sumN += curN;
        multD += curN * (n - i - 1);
    }
    long long prize;
    scanf("%lld", &prize);
    printf("%lld", (prize - sumN) / multD);
    return 0;
}