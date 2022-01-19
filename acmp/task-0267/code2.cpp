#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int n, t1, t2;
    scanf("%d %d %d", &n, &t1, &t2);
    int minTime = 1LL * (n - 1) * t1 * t2 / (t1 + t2);
    int nT1 = minTime / t1;
    int nT2 = minTime / t2;
    if (nT1 + nT2 == n - 1) {
        minTime += std::min(t1, t2);
    } else if (nT1 + nT2 == n - 2) {
        minTime = std::min((nT1 + 1) * t1, (nT2 + 1) * t2) + std::min(t1, t2);
    }
    printf("%d", minTime);
    return 0;
}