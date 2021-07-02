#include <stdio.h>
#include <math.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n)

struct Coord {

    int x;

    int y;

    double len(Coord coord) {
        return sqrt(pow(x - coord.x, 2) + pow(y - coord.y, 2));
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Coord> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &list[i].x, &list[i].y);
    }
    double minLength = INT_MAX;
    int idMinI = 1;
    int idMinJ = 2;
    double maxLength = INT_MIN;
    int idMaxI = 1;
    int idMaxJ = 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double length = list[i].len(list[j]);
            if (length > maxLength) {
                maxLength = length;
                idMaxI = i + 1;
                idMaxJ = j + 1;
            }
            if (length < minLength) {
                minLength = length;
                idMinI = i + 1;
                idMinJ = j + 1;
            }
        }
    }
    printf("%d %d\n", idMinI, idMinJ);
    printf("%d %d", idMaxI, idMaxJ);
    return 0;
}