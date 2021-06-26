#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int n;
    int prev;
    scanf("%d", &n);
    int sum = n;
    do {
        prev = n;
        scanf("%d", &n);
        sum += n;
    } while (n != 0 || prev != 0);
    printf("%d", sum);
    return 0;
}