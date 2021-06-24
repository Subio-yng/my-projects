#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int sum = 0;
    int length = 0;
    while (n != 0) {
        sum += n;
        length++;
        scanf("%d", &n);
    }
    printf("%.3f", sum * 1.0 / length);
    return 0;
}