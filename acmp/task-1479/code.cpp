#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    long long n, div;
    scanf("%lld %lld", &n, &div);
    div = std::llabs(div);
    printf("%lld", (n % div + div) % div);
    return 0;
}