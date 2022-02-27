#include <stdio.h>
 
// Time complexity: O(1)
// Space complexity: O(1)
 
int main() {
    long long n, lvl;
    scanf("%lld %lld", &n, &lvl);
    long long rooms = (n + (n - 2) * lvl) / 2 * lvl;
    if ((n + (n - 2) * lvl) % 2 == 1) {
        rooms += lvl / 2;
    }
    printf("%lld", 1 + rooms);
    return 0;
}