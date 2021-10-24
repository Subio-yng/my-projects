#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    if (1 <= n && n <= 10) {
        printf("nine");
    } else {
        printf("error");
    }
    return 0;
}