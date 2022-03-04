#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)
 
int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 1) {
        printf("0");
        return 0;
    }
    n /= 2;
    std::vector<int> ways(n + 1, 0);
    ways[0] = 1;
    for (int cur = 1; cur <= n; cur++) {
        if (cur == 1) {
            ways[cur] = ways[cur - 1] + 2 * ways[cur - 1];
        } else {
            ways[cur] = 4 * ways[cur - 1] - ways[cur - 2];
        }
    }
    printf("%d", ways[n]);
    return 0;
}