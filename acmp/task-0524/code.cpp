#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

bool moveBishop(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) == abs(y1 - y2);
}

int main() {
    const int BOARD_SIZE = 8;
    int destX, destY, curX, curY;
    scanf("%d %d %d %d", &destX, &destY, &curX, &curY);
    if ((destX + destY) % 2 != (curX + curY) % 2 || destX == curX && destY == curY) {
        printf("0");
    } else if (moveBishop(destX, destY, curX, curY)) {
        printf("1");
    } else {
        printf("2\n");
        int x1 = (destX - destY + curX + curY) / 2;
        int y1 = (-destX + destY + curX + curY) / 2;
        int x2 = (destX + destY + curX - curY) / 2;
        int y2 = (destX + destY - curX + curY) / 2;
        if (1 <= x1 && x1 <= BOARD_SIZE &&
            1 <= y1 && y1 <= BOARD_SIZE
        ) {
            printf("%d %d", x1, y1);
        } else {
            printf("%d %d", x2, y2);
        }
    }
    return 0;
}