#include <stdio.h>
#include <math.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    long long maxPower;
    if (n % 3 == 0) {
        maxPower = pow(3.0, n / 3);
    } else if (n % 3 == 1) {
        maxPower = pow(3.0, n / 3 - 1) * 2 * 2;
    } else {
        maxPower = pow(3.0, n / 3) * 2;
    }
    printf("%lld", maxPower);
    return 0;
}