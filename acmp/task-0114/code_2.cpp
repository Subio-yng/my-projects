#include <stdio.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    int n, base;
    scanf("%d %d", &n, &base);
    int count0 = base - 1;
    int count1 = base * (base - 1);
    int count2 = count1;
    for (int i = 2; i < n; i++) {
        count2 = (count1 + count0) * (base - 1);
        count0 = count1;
        count1 = count2;
    }
    printf("%d", count2);
    return 0;
}