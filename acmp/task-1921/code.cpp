#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int nGirls = (a + 1) / (a - b);
    long long nBoys = 1LL * nGirls * b + 1;
    printf("%lld\n%d", nBoys, nGirls);
    return 0;
}