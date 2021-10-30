#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    long n, m;
    scanf("%ld %ld", &n, &m);
    printf("%ld", std::min(std::min(n, m), (n + m) / 3));
    return 0;
}