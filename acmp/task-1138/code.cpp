#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int n;
    int max1 = 0, max2 = 0;
    do {
        scanf("%d", &n);
        if (n > max1) {
            max2 = max1;
            max1 = n;
        } else if (n > max2) {
            max2 = n;
        }
    } while (n != 0);
    printf("%d", max2);
    return 0;
}