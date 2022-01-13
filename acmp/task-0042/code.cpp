#include <stdio.h>

// Time complexity: O(log(n))
// Space complexity: O(1)

long long getPow(int n, int exp) {
    if (exp == 0) {
        return 1;
    }
    long long halfExp = getPow(n, exp / 2);
    if (exp % 2 == 0) {
        return halfExp * halfExp;
    } else {
        return halfExp * halfExp * n;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    long long maxPower;
    if (n % 3 == 0 || n == 1) {
        maxPower = getPow(3, n / 3);
    } else if (n % 3 == 1) {
        maxPower = getPow(3, n / 3 - 1) * 2 * 2;
    } else {
        maxPower = getPow(3, n / 3) * 2;
    }
    printf("%lld", maxPower);
    return 0;
}