#include <stdio.h>
#include <algorithm>

// Time complexity: O(log(cubes))
// Space complexity: O(1)

long long getPow(int n, int exp) {
    if (exp == 0) {
        return 1;
    }
    long long halfExp = getPow(n, exp / 2);
    if (exp % 2 == 0) {
        return halfExp * halfExp;
    } else {
        return halfExp * halfExp * n;
    }
}

int main() {
    const long long MAX_LEN = 2 * getPow(10, 18);
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