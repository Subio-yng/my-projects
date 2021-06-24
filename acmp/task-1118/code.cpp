#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int divCeil(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int height, day, night;
    scanf("%d %d %d", &height, &day, &night);
    if (day > height) {
        printf("1");
    } else {
        printf("%d", divCeil(height - day, day - night) + 1);
    }
    return 0;
}