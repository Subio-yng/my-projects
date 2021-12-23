#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    std::sort(list.begin(), list.end());
    std::vector<int> minGab(n);
    minGab[1] = list[1] - list[0];
    for (int cur = 2; cur < n; cur++) {
        if (cur == 2) {
            minGab[cur] = list[cur] - list[cur - 2];
        } else if (cur == 3) {
            minGab[cur] = std::max(minGab[cur - 2], list[cur] - list[cur - 1]);
        } else {
            minGab[cur] = std::min(
                std::max(minGab[cur - 2], list[cur] - list[cur - 1]),
                std::max(minGab[cur - 3], list[cur] - list[cur - 2])
            );
        }
    }
    printf("%d", minGab[n - 1]);
    return 0;
}