#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

struct Coord {

    int x;

    int y;

    static Coord read() {
        Coord a;
        scanf(" %c%c", &a.x, &a.y);
        a.x -= 'a';
        a.y -= '1';
        return a;
    }
};

bool isQueenMove(Coord queen, Coord figure) {
    return queen.x == figure.x || queen.y == figure.y ||
        abs(queen.x - figure.x) == abs(queen.y - figure.y);
}

bool onOneLine(Coord queen, Coord bK, Coord wK) {
    int c1 = queen.x, c2 = queen.y;
    queen.x = bK.x - c1;
    queen.y = bK.y - c2;
    bK.x = wK.x - c1;
    bK.y = wK.y - c2;
    return abs(queen.x * bK.y - bK.x * queen.y) / 2.0 == 0;
}

bool isInOrder(int queen, int wK, int bK) {
    return std::min(queen, bK) <= wK &&
        wK <= std::max(queen, bK);
}

int main() {
    Coord whiteKing = Coord::read();
    Coord whiteQueen = Coord::read();
    Coord blackKing = Coord::read();
    if (isQueenMove(whiteQueen, blackKing)) {
        if (onOneLine(whiteQueen, blackKing, whiteKing)) {
            if (isInOrder(whiteQueen.x, whiteKing.x, blackKing.x) &&
                isInOrder(whiteQueen.y, whiteKing.y, blackKing.y)
            ) {
                printf("NO");
            } else {
                printf("YES");
            }
        } else {
            printf("YES");
        }
    } else {
        printf("NO");
    }
    return 0;
}