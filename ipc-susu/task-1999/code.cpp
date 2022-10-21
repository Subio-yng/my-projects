#include <stdio.h>
#include <algorithm>

int main() {
    int a, b, x, y;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    int ans = std::min(a + x, b + y);
    if (y - b == x - a) {
        ans = std::min(ans, abs(y - b));
    }
    printf("%d", ans);
    return 0;
}