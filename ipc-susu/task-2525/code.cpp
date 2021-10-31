#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld", std::min(std::min(n, m), (n + m) / 3));
    return 0;
}