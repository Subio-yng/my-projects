#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x1, y1;
    scanf("%d %d", &x1, &y1);
    int x2, y2;
    scanf("%d %d", &x2, &y2);
    if ((x2 + 2 == x1 || x2 - 2 == x1) &&
        (y2 + 1 == y1 || y2 - 1 == y1) ||
        (y2 + 2 == y1 || y2 - 2 == y1) &&
        (x2 + 1 == x1 || x2 - 1 == x1)
    ) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}