#include <stdio.h>
#include <algorithm>

// Time complexity: O(log(cubes))
// Space complexity: O(1)

int main() {
    const long long MAX_LEN = 2000000000000000000;
    long long n1, n2, n3, n4;
    scanf("%lld %lld %lld %lld", &n1, &n2, &n3, &n4);
    long long cubes = std::min(n1, n2) + std::min(n3, n4);
    long long left = 0;
    long long right = MAX_LEN;
    while (left + 1 < right) {
        long long mid = (left + right) / 2;
        if (cubes / mid <= mid) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (right > cubes / right) {
        right--;
    }
    printf("%lld", right);
    return 0;
}