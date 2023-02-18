#include <bits/stdc++.h>

// Time complexity: O(log(RANGE))
// Space complexity: O(1)

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a < 0) {
        a *= -1;
        b *= -1;
        c *= -1;
        d *= -1;
    }
    const double INF = 1'000'000.0;
    double left = -INF;
    double right = INF;
    const double EPS = 1e-4;
    while (right - left > EPS) {
        double mid = (left + right) / 2.0;
        double curVal = a * mid * mid * mid + b * mid * mid + c * mid + d;
        if (curVal <= 0) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%.3f", left);
    return 0;
}