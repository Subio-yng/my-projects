#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    const long long INF_POINT = 1'000'000'000;
    const int CNT_COORDS = 3;
    long long sumX, sumY;
    scanf("%lld %lld", &sumX, &sumY);
    if (abs(sumX) == INF_POINT ||
        abs(sumY) == INF_POINT ||
        sumX == 0 || sumY == 0
        ) {
        printf("NO");
        return 0;
    }
    sumX *= 3;
    sumY *= 3;
    std::vector<int> pointX(CNT_COORDS, 0);
    for (int i = 0; i < CNT_COORDS; i++) {
        pointX[i] = std::min(abs(sumX), INF_POINT);
        if (sumX < 0) {
            pointX[i] *= -1;
        }
        sumX -= pointX[i];
        if (sumX == 0) {
            break;
        }
    }
    std::vector<int> pointY(CNT_COORDS, 0);
    for (int i = 1; i <= CNT_COORDS; i++) {
        i %= CNT_COORDS;
        pointY[i] = std::min(abs(sumY), INF_POINT);
        if (sumY < 0) {
            pointY[i] *= -1;
        }
        sumY -= pointY[i];
        if (sumY == 0) {
            break;
        }
    }
    printf("YES\n");
    for (int i = 0; i < CNT_COORDS; i++) {
        printf("%d %d\n", pointX[i], pointY[i]);
    }
    return 0;
}