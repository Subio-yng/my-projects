#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

long long getCnt(int i1, int j1, int i2, int j2) {
    int distI = i2 - i1 + 1;
    int distJ = j2 - j1 + 1;
    return 1LL * distI * (distI + 1) / 2 * distJ * (distJ + 1) / 2;
}

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    int posI, posJ;
    scanf("%d %d", &posI, &posJ);
    printf("%lld", getCnt(1, 1, posI - 1, sizeJ)
                   + getCnt(1, 1, sizeI, posJ - 1)
                   - getCnt(1, 1, posI - 1, posJ - 1)
                   + getCnt(1, posJ + 1, sizeI, sizeJ)
                   - getCnt(1, posJ + 1, posI - 1, sizeJ)
                   + getCnt(posI + 1, 1, sizeI, sizeJ)
                   - getCnt(posI + 1, posJ + 1, sizeI, sizeJ)
                   - getCnt(posI + 1, 1, sizeI, posJ - 1));
    return 0;
}