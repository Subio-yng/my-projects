#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int length = 0;
    int n;
    scanf("%d", &n);
    while (n != 0) {
        length++;
        scanf("%d", &n);
    }
    printf("%d", length);
    return 0;
}