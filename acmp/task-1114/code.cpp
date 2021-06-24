#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int DISTANCE = 109;
    int speed, time;
    scanf("%d %d", &speed, &time);
    int ans = speed * time % DISTANCE + 1;
    if (speed < 0) {
        ans += DISTANCE;
    }
    printf("%d", ans);
    return 0;
}