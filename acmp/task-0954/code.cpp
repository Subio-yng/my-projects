#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    const int MOD = 1000000;
    int n;
    scanf("%d", &n);
    std::vector<int> ways(n + 12, 0);
    ways[10] = 2;
    ways[11] = 2;
    ways[12] = 2;
    for (int cur = 20; cur <= n; cur++) {
        ways[cur] = (ways[cur - 10] + ways[cur - 11] + ways[cur - 12]) % MOD;
    }
    printf("%d", ways[n]);
    return 0;
}