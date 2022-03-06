#include <stdio.h>
#include <vector>
#include <math.h>
 
// Time complexity: O(n^2)
// Space complexity: O(n)
 
struct Coord {
 
    int x;
 
    int y;
 
    double getLen(const int x1, const int y1) {
        return sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
    }
};
 
int main() {
    int n; 
    long long price, money;
    scanf("%d %lld %lld", &n, &price, &money);
    std::vector<Coord> houses(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &houses[i].x, &houses[i].y);
    }
    int xNet, yNet;
    scanf("%d %d", &xNet, &yNet);
    double minLength = -1;
    for (int i = 0; i < n; i++) {
        double curLen = houses[i].getLen(xNet, yNet);
        for (int j = 0; j < n; j++) {
            curLen += houses[i].getLen(houses[j].x, houses[j].y);
        }
        if (minLength == -1 || curLen < minLength) {
            minLength = curLen;
        }
    }
    if (minLength * price > money) {
        printf("NO");
    } else {
        printf("YES");
    }
    return 0;
}