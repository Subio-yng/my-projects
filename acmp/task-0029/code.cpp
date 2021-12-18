#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list(n + 2);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &list[i]);
    }
    std::vector<int> stage(n + 2);
    stage[1] = 0;
    stage[2] = abs(list[2] - list[1]);
    for (int cur = 3; cur <= n; cur++) {
        stage[cur] = std::min(stage[cur - 2] + 3 * abs(list[cur - 2] - list[cur]),
                              stage[cur - 1] + abs(list[cur - 1] - list[cur]));
    }
    printf("%d", stage[n]);
    return 0;
}