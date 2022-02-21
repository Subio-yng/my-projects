#include <stdio.h>
#include <vector>
 
// Time complexity: O(n)
// Space complexity: O(n)
 
int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> ways(n + 2);
    ways[1] = 1;
    ways[2] = 2;
    for (int cur = 3; cur <= n; cur++) {
        ways[cur] = ways[cur - 2] + ways[cur / 2];
    }
    printf("%d", ways[n]);
    return 0;
}