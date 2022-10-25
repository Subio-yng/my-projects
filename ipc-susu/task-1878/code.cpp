#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int getV() {
    int l, w, h;
    scanf("%d %d %d", &l, &w, &h);
    return l * w * h;
}

int main() {
    int v1 = getV();
    int v2 = getV();
    if (v1 > v2) {
        printf("FIRST");
    } else if (v1 < v2) {
        printf("SECOND");
    } else {
        printf("EQUAL");
    }
    return 0;
}