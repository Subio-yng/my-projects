#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

// Time complexity: O(1)
// Space complexity: O(1)

bool moveRook(int x1, int y1, int x2, int y2) {
    return x1 == x2 || y1 == y2;
}

bool moveBishop(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) == abs(y1 - y2);
}

bool moveQueen(int x1, int y1, int x2, int y2) {
    return x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2);
}

bool moveKnight(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == 5;
}

bool moveKing(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) < 2 && abs(y1 - y2) < 2;
}

bool movePawn(int x1, int y1, int x2, int y2) {
    return (x1 == x2 && (y2 - y1 == 1 || y2 - y1 == 2) && y1 > '1') &&
        !(x1 != 2 && x2 - x1 == 2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char x1, y1;
    scanf("%c%c", &x1, &y1);
    char x2, y2;
    scanf(" %c%c", &x2, &y2);
    std::vector<std::string> figures;
    if (moveRook(x1, y1, x2, y2)) {
        figures.push_back("Rook");
    }
    if (moveBishop(x1, y1, x2, y2)) {
        figures.push_back("Bishop");
    }
    if (moveQueen(x1, y1, x2, y2)) {
        figures.push_back("Queen");
    }
    if (moveKnight(x1, y1, x2, y2)) {
        figures.push_back("Knight");
    }
    if (moveKing(x1, y1, x2, y2)) {
        figures.push_back("King");
    }
    if (movePawn(x1, y1, x2, y2)) {
        figures.push_back("Pawn");
    }
    for (int i = 0; i < (int) figures.size(); i++) {
        printf("%s\n", figures[i].c_str());
    }
    if ((int) figures.size() == 0) {
        printf("Nobody");
    }
    return 0;
}