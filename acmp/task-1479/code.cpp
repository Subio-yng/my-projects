#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    long long n, div;
    scanf("%lld %lld", &n, &div);
    long long remnant = n % div;
    if (remnant < 0) {
        if (div < 0) {
            remnant += div * -1;
        } else {
            remnant += div;
        }
    }
    printf("%lld", remnant);
    return 0;
}