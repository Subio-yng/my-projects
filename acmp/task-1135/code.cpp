#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int evenCount = 0;
    while (n != 0) {
        if (n % 2 == 0) {
            evenCount++;
        }
        scanf("%d", &n);
    }
    printf("%d", evenCount);
    return 0;
}