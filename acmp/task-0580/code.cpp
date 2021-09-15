#include <stdio.h>
#include <math.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int line1, line2, line3;
    scanf("%d %d %d", &line1, &line2, &line3);
    int radius;
    scanf("%d", &radius);
    long double p = (line1 + line2 + line3) / 2.0;
    long double s = sqrt(p * (p - line1) * (p - line2) * (p - line3));
    if (radius <= s / p) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}