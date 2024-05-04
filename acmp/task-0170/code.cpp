#include <bits/stdc++.h>

// Time complexity: O(sqrt(n))
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    int left = 0;
    int right = n + 1;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (1LL * mid * (mid + 1) / 2 > n) {
            right = mid;
        } else {
            left = mid;
        }
    }
    int len = left;
    while ((n - len * (len + 1) / 2) % len != 0) {
        len--;
    }
    printf("%d", len);
    return 0;
}