#include <stdio.h>
#include <algorithm>

// Time complexity: O(log(kind1))
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    long long kind1, kind2;
    scanf("%lld %lld", &kind1, &kind2);
    if (kind2 > kind1) {
        std::swap(kind1, kind2);
    }
    while (kind1 != kind2) {
        kind1 /= 2;
        if (kind1 < kind2) {
            kind2 /= 2;
        }
    }
    printf("%lld", kind1);
    return 0;
}