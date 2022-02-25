#include <stdio.h>
 
// Time complexity: O(lvl)
// Space complexity: O(1)
 
int main() {
    int n, lvl;
    scanf("%d %d", &n, &lvl);
    long long rooms = n;
    int common = 3;
    for (int curLvl = 2; curLvl <= lvl; curLvl++) {
        rooms += n * curLvl - common;
        common += 2;
    }
    printf("%lld", rooms);
    return 0;
}