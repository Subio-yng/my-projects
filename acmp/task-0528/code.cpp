#include <stdio.h>
 
// Time complexity: O(1)
// Space complexity: O(1)
 
int main() {
    long long n, lvl;
    scanf("%lld %lld", &n, &lvl);
    printf("%lld", 1 + lvl + (n - 2) * (lvl + 1) * lvl / 2);
    return 0;
}