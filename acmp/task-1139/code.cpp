#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int max = 0;
    int maxCount = 0;
    int n;
    do {
        scanf("%d", &n);
        if (n > max) {
            max = n;
            maxCount = 1;
        } else if (n == max) {
            maxCount++;
        }
    } while (n != 0);
    printf("%d", maxCount);
    return 0;
}