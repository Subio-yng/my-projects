#include <stdio.h>
#include <algorithm>

// Time complexity: O(log(n * max(t1, t2)))
// Space complexity: O(1)

int main() {
    int n, t1, t2;
    scanf("%d %d %d", &n, &t1, &t2);
    n--;
    long long left = 0;
    long long right = n * std::max(t1, t2);
    while (left + 1 < right) {
        long long mid = (left + right) / 2;
        if (mid / t1 + mid / t2 < n) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%lld", std::min(t1, t2) + right);
    return 0;
}