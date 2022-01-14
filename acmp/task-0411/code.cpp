#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("-1");
            } else {
                printf("0");
            }
        } else if (c == 0) {
            printf("1\n0");
        } else {
            printf("1\n%lf", (double) -c / b);
        }
    } else if (b == 0) {
        if ((double) -c / a < 0) {
            printf("0");
        } else if ((double) -c / a == 0) {
            printf("1\n0");
        } else {
            printf("2\n%lf\n%lf", sqrt((double) -c / a), -sqrt((double) -c / a));
        }
    } else if (c == 0) {
        printf("2\n0\n%lf", (double) -b / a);
    } else {
        long long d = b * b - 1LL * 4 * a * c;
        if (d < 0) {
            printf("0");
        } else if (d == 0) {
            printf("1\n%lf", -b / 2.0 / a);
        } else {
            printf("2\n%lf\n%lf", (-b - sqrt(d)) / 2.0 / a,
                   (-b + sqrt(d)) / 2.0 / a);
        }
    }
    return 0;
}