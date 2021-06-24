#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int DISTANCE = 109;
    int speed, hours;
    scanf("%d %d", &speed, &hours);
    int ans = speed * hours % DISTANCE + 1;
    if (speed < 0) {
        ans += DISTANCE;
    }
    printf("%d", ans);
    return 0;
}