#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n^2)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    std::vector<int> lenSubSeq(n, 1);
    for (int cur = 1; cur < n; cur++) {
        for (int prev = 0; prev < cur; prev++) {
            if (list[prev] < list[cur]) {
                lenSubSeq[cur] = std::max(lenSubSeq[cur], lenSubSeq[prev] + 1);
            }
        }
    }
    int max = 1;
    for (int i = 0; i < n; i++) {
        max = std::max(max, lenSubSeq[i]);
    }
    printf("%d", max);
    return 0;
}