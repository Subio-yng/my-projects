#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int sum = 0;
    while (n != 0) {
        sum += n;
        scanf("%d", &n);
    }
    printf("%d", sum);
    return 0;
}