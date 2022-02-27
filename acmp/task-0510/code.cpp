#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)
 
int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> ways(n + 1, 0);
    ways[0] = 1;
    for (int cur = 2; cur <= n; cur += 2) {
        if (cur == 2) {
            ways[cur] = ways[cur - 2] + 2 * ways[cur - 2];
        } else {
            ways[cur] = 4 * ways[cur - 2] - ways[cur - 4];
        }
    }
    printf("%d", ways[n]);
    return 0;
}