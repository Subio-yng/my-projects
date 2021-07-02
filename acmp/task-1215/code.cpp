#include <stdio.h>
#include <math.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    int x;
    scanf("%d", &x);
    int ans = list[0];
    for (int i = 1; i < n; i++) {
        if (abs(x - list[i]) < abs(x - ans) ||
            abs(x - list[i]) == abs(x - ans) && list[i] < ans
        ) {
            ans = list[i];
        }
    }
    printf("%d", ans);
    return 0;
}