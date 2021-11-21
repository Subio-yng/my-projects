#include <stdio.h>

// Time complexity: O(sqrt(n))
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    int k = 0;
    int z = 1000;
    while (n > 0 && z > 0) {
        if (n >= z * z) {
            k++;
            n -= z * z;
        } else {
            z--;
        }
    }
    printf("%d", k);
    return 0;
}