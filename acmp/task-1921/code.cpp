#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int girl = (a + 1) / (a - b);
    long long boy = 1LL * girl * b + 1;
    printf("%lld\n%d", boy, girl);
    return 0;
}