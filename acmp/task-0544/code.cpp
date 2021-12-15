#include <stdio.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    long long step0 = 0;
    long long step1 = 0;
    long long step2 = 1;
    long long step3 = 0;
    for (int i = 1; i <= n; i++) {
        step3 = step2 + step1 + step0;
        step0 = step1;
        step1 = step2;
        step2 = step3;
    }
    printf("%lld", step3);
    return 0;
}