#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

bool moveBishop(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) == abs(y1 - y2);
}

int main() {
    const int BOARD_SIZE = 8;
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if ((x1 + y1) % 2 != (x2 + y2) % 2 || x1 == x2 && y1 == y2) {
        printf("0");
    } else if (moveBishop(x1, y1, x2, y2)) {
        printf("1");
    } else {
        for (int x3 = 1; x3 <= BOARD_SIZE; x3++) {
            for (int y3 = 1; y3 <= BOARD_SIZE; y3++) {
                if (moveBishop(x1, y1, x3, y3) && moveBishop(x2, y2, x3, y3)) {
                    printf("2\n%d %d", x3, y3);
                    return 0;
                }
            }
        }
    }
    return 0;
}