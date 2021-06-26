#include <stdio.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    int cur;
    int prev;
    scanf("%d", &cur);
    int maxCount = 1, curCount = 1;
    do {
        prev = cur;
        scanf("%d", &cur);
        if (cur == prev) {
            curCount++;
        } else {
            if (curCount > maxCount) {
                maxCount = curCount;
            }
            curCount = 1;
        }
    } while (cur != 0);
    printf("%d", maxCount);
    return 0;
}