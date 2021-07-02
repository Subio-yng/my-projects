#include <stdio.h>
#include <math.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n)

struct Coord {

    int x;

    int y;

    double Len(int x2, int y2) {
        return sqrt(pow(x - x2, 2) + pow(y - y2, 2));
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Coord> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &list[i].x, &list[i].y);
    }
    double minLenght = INT_MAX;
    int idMinI = 1;
    int idMinJ = 2;
    double maxLenght = INT_MIN;
    int idMaxI = 1;
    int idMaxJ = 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (list[i].Len(list[j].x, list[j].y) > maxLenght) {
                maxLenght = list[i].Len(list[j].x, list[j].y);
                idMaxI = i + 1;
                idMaxJ = j + 1;
            }
            if (list[i].Len(list[j].x, list[j].y) < minLenght) {
                minLenght = list[i].Len(list[j].x, list[j].y);
                idMinI = i + 1;
                idMinJ = j + 1;
            }
        }
    }
    printf("%d %d\n", idMinI, idMinJ);
    printf("%d %d", idMaxI, idMaxJ);
    return 0;
}