#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

struct Coord {

    int x;

    int y;

    static Coord read() {
        char x1, y1;
        scanf("%c%c", &x1, &y1);
        Coord a;
        a.x = x1 - 'a' + 1;
        a.y = y1 - '0';
        return a;
    }
};

bool moveKnight(int x1, int y1, int x2, int y2) {
    return 1 <= x1 && x1 <= 8 &&
        1 <= y1 && y1 <= 8 &&
        (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == 5;
}

int main() {
    Coord start = Coord::read();
    scanf(", ");
    Coord end = Coord::read();
    if (moveKnight(start.x, start.y, end.x, end.y)) {
        printf("1");
    } else if (moveKnight(start.x - 1, start.y - 2, end.x, end.y) ||
               moveKnight(start.x - 1, start.y + 2, end.x, end.y) ||
               moveKnight(start.x + 1, start.y - 2, end.x, end.y) ||
               moveKnight(start.x + 1, start.y + 2, end.x, end.y) ||
               moveKnight(start.x - 2, start.y + 1, end.x, end.y) ||
               moveKnight(start.x + 2, start.y + 1, end.x, end.y) ||
               moveKnight(start.x + 2, start.y - 1, end.x, end.y) ||
               moveKnight(start.x - 2, start.y - 1, end.x, end.y)
               ) {
        printf("2");
    } else {
        printf("NO");
    }
    return 0;
}