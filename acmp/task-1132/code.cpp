#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int length = -1;
    int n;
    do {
        scanf("%d", &n);
        length++;
    } while (n != 0);
    printf("%d", length);
    return 0;
}