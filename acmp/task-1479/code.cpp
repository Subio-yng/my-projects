#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

long long abs(long long a) {
    if (a < 0) {
        return a * -1;
    }
    return a;
}

int main() {
    long long n, div;
    scanf("%lld %lld", &n, &div);
    printf("%lld", (n % div + abs(div)) % div);
    return 0;
}