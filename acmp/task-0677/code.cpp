#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int x = a * b * c * d;
    int tmp = a * b * c - b * c - a * c - a * b;
    if (tmp > 0 && x > tmp && x % tmp == 0) {
        x /= tmp;
        if (x % a == 0 && x % b == 0 && x % c == 0 &&
            x / a + x / b + x / c + d == x
        ) {
            printf("%d", x);
        } else {
            printf("-1");
        }
    } else {
        printf("-1");
    }
    return 0;
}