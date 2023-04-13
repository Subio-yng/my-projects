#include <bits/stdc++.h>

// Time complexity: O(log(r))
// Space complexity: O(1)

double getValue(double x, double r, double a, double b) {
    return x * a + b * sqrt(std::max(0.0, r * r - x * x));
}

int main() {
    double a, b, r;
    scanf("%lf %lf %lf", &a, &b, &r);
    double x = 1.0;
    if (a < 0) {
        a *= -1;
        x *= -1;
    }
    double y = 1.0;
    if (b < 0) {
        b *= -1;
        y *= -1;
    }
    double leftX = 0.0;
    const double EPS = 1e-6;
    double rightX = r + EPS;
    while (rightX - leftX > EPS) {
        double leftMid = (2.0 * leftX + rightX) / 3.0;
        double rightMid = (leftX + 2.0 * rightX) / 3.0;
        if (getValue(leftMid, r, a, b) > getValue(rightMid, r, a, b)) {
            rightX = rightMid;
        } else {
            leftX = leftMid;
        }
    }
    x *= leftX;
    y *= sqrt(r * r - x * x);
    printf("%.6f\n", getValue(leftX, r, a, b));
    printf("%.6f %.6f", x, y);
    return 0;
}