#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int count = 0;
    while (n != 0) {
        int prev = n;
        scanf("%d", &n);
        if (n > prev) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}