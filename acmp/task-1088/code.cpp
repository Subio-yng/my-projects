#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char x1, y1;
    scanf("%c%c", &x1, &y1);
    char x2, y2;
    scanf(" %c%c", &x2, &y2);
    bool ans = true;
    if (x1 == x2 || y1 == y2) {
        printf("Rook\n");
        printf("Queen\n");
        ans = false;
    } else if (abs(x1 - x2) == abs(y1 - y2)) {
        printf("Bishop\n");
        printf("Queen\n");
        ans = false;
    }
    if ((x1 + 2 == x2 || x1 - 2 == x2) &&
        (y1 + 1 == y2 || y1 - 1 == y2) ||
        (y1 + 2 == y2 || y1 - 2 == y2) &&
        (x1 + 1 == x2 || x1 - 1 == x2)
    ) {
        printf("Knight\n");
        ans = false;
    }
    if (abs(x1 - x2) < 2 && abs(y1 - y2) < 2) {
        printf("King\n");
        ans = false;
    }
    if ((x1 == x2 && (y2 - y1 == 1 || y2 - y1 == 2) && y1 > '1') &&
        !(x1 != 2 && x2 - x1 == 2)
    ) {
        printf("Pawn");
        ans = false;
    }
    if (ans) {
        printf("Nobody");
    }
    return 0;
}