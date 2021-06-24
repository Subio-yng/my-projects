#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    do {
        int prev = n;
        scanf("%d", &n);
        if (n > prev) {
            count++;
        }
    } while (n != 0);
    printf("%d", count);
    return 0;
}