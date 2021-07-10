#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

struct Coord {

    int i;

    int j;

    static Coord read() {
        char i1, j1;
        scanf("%c%c", &i1, &j1);
        Coord a;
        a.i = i1 - 'a' + 1;
        a.j = j1 - '0';
        return a;
    }
};

bool isCorrectMove(int i, int j) {
    return 1 <= i && i <= 8 &&
        1 <= j && j <= 8;
}

bool moveKnight(int i1, int j1, int i2, int j2) {
    return isCorrectMove(i1, j1) &&
        (i1 - i2) * (i1 - i2) + (j1 - j2) * (j1 - j2) == 5;
}

int main() {
    Coord start = Coord::read();
    scanf(", ");
    Coord end = Coord::read();
    if (moveKnight(start.i, start.j, end.i, end.j)) {
        printf("1");
    } else {
        for (int i = 1; i <= 2; i++) {
            if (moveKnight(start.i - i, start.j - (3 - i), end.i, end.j) ||
                moveKnight(start.i + i, start.j - (3 - i), end.i, end.j) ||
                moveKnight(start.i + i, start.j + (3 - i), end.i, end.j) ||
                moveKnight(start.i - i, start.j + (3 - i), end.i, end.j)
            ) {
                printf("2");
                return 0;
            }
        }
        printf("NO");
    }
    return 0;
}