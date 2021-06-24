#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int max = n;
    while (n != 0) {
        if (max < n) {
            max = n;
        }
        scanf("%d", &n);
    }
    printf("%d", max);
    return 0;
}