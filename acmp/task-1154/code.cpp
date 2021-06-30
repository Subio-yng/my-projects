#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    const int MAXIP = 255;
    const int MINIP = 0;
    long long n1 = -1;
    long long n2 = -1;
    long long n3 = -1;
    long long n4 = -1;
    scanf("%lld.%lld.%lld.%lld", &n1, &n2, &n3, &n4);
    if (MINIP <= n1 && n1 <= MAXIP &&
        MINIP <= n2 && n2 <= MAXIP &&
        MINIP <= n3 && n3 <= MAXIP &&
        MINIP <= n4 && n4 <= MAXIP
        ) {
        printf("Good");
    } else {
        printf("Bad");
    }
    return 0;
}