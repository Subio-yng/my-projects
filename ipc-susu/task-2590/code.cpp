#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int n1, n2, n3, n4, size;
    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &size);
    if (n3 + n4 <= size) {
        printf("1");
    } else if (n2 + n3 <= size) {
        printf("2");
    } else if (n1 + n2 <= size) {
        printf("3");
    } else {
        printf("4");
    }
    return 0;
}