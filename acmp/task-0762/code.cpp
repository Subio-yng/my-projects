#include <stdio.h>

// Time complexity: O(log_3(n))
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    while (n > 1) {
        count++;
        n = (n + 2) / 3;
    }
    printf("%d", count);
    return 0;
}