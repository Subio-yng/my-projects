#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int y1, x1;
    scanf("%d %d", &y1, &x1);
    int y2, x2;
    scanf("%d %d", &y2, &x2);
    if (y1 == y2 && (x2 - x1 == 1 || x2 - x1 == 2) && x1 > 1) {
        if (x1 != 2 && x2 - x1 == 2) {
            printf("NO");
        } else {
            printf("YES");
        }
    } else {
        printf("NO");
    }
    return 0;
}