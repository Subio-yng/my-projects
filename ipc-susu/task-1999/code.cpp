#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int a, b, x, y;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    if (x + y == b - a || x - y == b - a) {
        printf("%d", a + x);
    } else {
        printf("%d", a - x);
    }
    return 0;
}