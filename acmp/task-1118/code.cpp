#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int div(int a, int b) {
    if (a < 0) {
        return 0;
    }
    return (a + b - 1) / b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int height, day, night;
    scanf("%d %d %d", &height, &day, &night);
    printf("%d", div((height - day), (day - night)) + 1);
    return 0;
}