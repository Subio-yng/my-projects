#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    const int MOD = 1000000;
    int n;
    scanf("%d", &n);
    std::vector<int> ways(n + 1, 0);
    ways[0] = 1;
    for (int cur = 10; cur <= n; cur++) {
        ways[cur] = ways[cur - 10];
        if (cur > 10) {
            ways[cur] += ways[cur - 11];
        } 
        if (cur > 11) {
            ways[cur] += ways[cur - 12];
        }
        ways[cur] %= MOD;
    }
    printf("%d", (ways[n] * 2) % MOD);
    return 0;
}