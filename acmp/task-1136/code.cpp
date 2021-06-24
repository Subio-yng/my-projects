#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int max = 0;
    int n;
    do {
        scanf("%d", &n);
        if (n > max) {
            max = n;
        }
    } while (n != 0);
    printf("%d", max);
    return 0;
}