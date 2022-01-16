#include <stdio.h>
#include <math.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == 0 && b == 0 && c == 0) {
        printf("-1");
    } else if (a == 0 && b == 0 && c != 0) {
        printf("0");
    } else if (a == 0 && b != 0) {
        double x = (double) -c / b;
        printf("1\n%lf", x);
    } else {
        long long d = b * b - 1LL * 4 * a * c;
        double x1 = (-b - sqrt(d)) / 2.0 / a;
        double x2 = (-b + sqrt(d)) / 2.0 / a;
        if (d < 0) {
            printf("0");
        } else if (d == 0) {
            printf("1\n%lf", x1);
        } else {
            printf("2\n%lf\n%lf", x1, x2);
        }
    }
    return 0;
}