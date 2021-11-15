#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    long long cookie1, price1, cookie2, price2, people;
    scanf("%lld %lld %lld %lld %lld", &cookie1, &price1, &cookie2, &price2, &people);
    long long cost1 = (people + cookie1 - 1) / cookie1 * price1;
    long long cost2 = (people + cookie2 - 1) / cookie2 * price2;
    if (cost1 < cost2) {
        printf("FIRST\n%lld", cost1);
    } else if (cost2 < cost1) {
        printf("SECOND\n%lld", cost2);
    } else {
        printf("ANY\n%lld", cost1);
    }
    return 0;
}