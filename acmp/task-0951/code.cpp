#include <stdio.h>
#include <vector>
#include <math.h>

// Time complexity: O(n * m * virus)
// Space compelxity: O(virus)

struct Coord {

    int x;

    int y;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int virus;
    scanf("%d", &virus);
    std::vector<Coord> vec(virus);
    for (int i = 0; i < virus; i++) {
        scanf("%d %d", &vec[i].x, &vec[i].y);
    }
    int maxSeconds = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int tempSeconds = 0;
            for (int k = 0; k < virus; k++) {
                if (k == 0 || abs(vec[k].x - i) + abs(vec[k].y - j) < tempSeconds) {
                    tempSeconds = abs(vec[k].x - i) + abs(vec[k].y - j);
                }
            }
            if (tempSeconds > maxSeconds) {
                maxSeconds = tempSeconds;
            }
        }
    }
    printf("%d", maxSeconds);
    return 0;
}