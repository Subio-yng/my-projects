#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    printf("%lld", 1LL * sizeI * (sizeI + 1) / 2 * sizeJ * (sizeJ + 1) / 2);
    return 0;
}