#include <stdio.h>
#include <math.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int x1, y1;
    scanf("%d %d", &x1, &y1);
    int x2, y2;
    scanf("%d %d", &x2, &y2);
    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        if (abs(x2 - x1) == abs(y2 - y1)) {
            printf("1");
        } else {
            printf("2");
        }
    } else {
        printf("0");
    }
    return 0;
}