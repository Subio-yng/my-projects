#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int evenCount = 0;
    int n;
    do {
        scanf("%d", &n);
        if (n > 0 && n % 2 == 0) {
            evenCount++;
        }
    } while (n != 0);
    printf("%d", evenCount);
    return 0;
}