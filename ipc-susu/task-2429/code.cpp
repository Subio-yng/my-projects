#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

long long ceilDiv(long long a, long long b) {
    return (a + b - 1) / b;
}

int main() {
    long long cookie1, price1, cookie2, price2, people;
    scanf("%lld %lld %lld %lld %lld", &cookie1, &price1, &cookie2, &price2, &people);
    long long cost1 = ceilDiv(people, cookie1) * price1;
    long long cost2 = ceilDiv(people, cookie2) * price2;
    if (cost1 < cost2) {
        printf("FIRST\n%lld", cost1);
    } else if (cost2 < cost1) {
        printf("SECOND\n%lld", cost2);
    } else {
        printf("ANY\n%lld", cost1);
    }
    return 0;
}