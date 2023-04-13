#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int n, len;
    scanf("%d %d", &n, &len);
    double rad = acos(-1.0) / n;
    if (len * (1.0 - std::cos(rad)) < 2.0 * std::sin(rad)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}