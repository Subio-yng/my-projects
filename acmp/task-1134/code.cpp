#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int sum = 0;
    int length = -1;
    int n;
    do {
        scanf("%d", &n);
        sum += n;
        length++;
    } while (n != 0);
    printf("%.3f", sum * 1.0 / length);
    return 0;
}