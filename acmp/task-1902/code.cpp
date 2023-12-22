#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    double S = abs(-b / 10.0 * 3 * a / 7.0 - b / 14.0 * 3 * a / 5.0) / 2.0;
    printf("%lf", S);
    return 0;
}