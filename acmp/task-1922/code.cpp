#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int len, qPos;
    scanf("%d %d", &len, &qPos);
    if (qPos < len) {
        printf("4");
    } else if (qPos == len) {
        printf("3");
    } else if (qPos < 2 * len) {
        printf("5");
    } else {
        printf("6");
    }
    return 0;
}