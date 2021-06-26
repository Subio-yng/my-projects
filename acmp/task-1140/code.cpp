#include <stdio.h>

// Time comeplexity: O(cur)
// Space complexity: O(1)

int main() {
    int cur;
    int prev;
    scanf("%d", &cur);
    int sum = cur;
    do {
        prev = cur;
        scanf("%d", &cur);
        sum += cur;
    } while (cur != 0 || prev != 0);
    printf("%d", sum);
    return 0;
}