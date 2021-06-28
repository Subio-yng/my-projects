#include <stdio.h>

// Time complexity: O(log(n))
// Space complexity: O(1)

int main() {
    long long n;
    scanf("%lld", &n);
    int count = 0;
    while (n > 1) {
        count++;
        n = (n + 1) >> 1;
    }
    printf("%d", count);
    return 0;
}