#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int sum = 0;
    int n;
    do {
        scanf("%d", &n);
        sum += n;
    } while (n != 0);
    printf("%d", sum);
    return 0;
}