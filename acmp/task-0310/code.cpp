#include <stdio.h>
 
// Time complexity: O(n)
// Space complexity: O(1)
 
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y, tile;
        scanf("%d %d %d", &x, &y, &tile);
        if (tile <= y && tile <= x &&
            (y % tile == 0 && (x - 1) % tile == 0 && (y - 2) % tile == 0 ||
             x % tile == 0 && (y - 1) % tile == 0 && (x - 2) % tile == 0 ||
             x % tile == 0 && (y - 2) % tile == 0 ||
             (x - 2) % tile == 0 && y % tile == 0 ||
             (x - 1) % tile == 0 && (y - 1) % tile == 0)
        ) {
            printf("1");
        } else {
            printf("0");
        }
    }
    return 0;
}