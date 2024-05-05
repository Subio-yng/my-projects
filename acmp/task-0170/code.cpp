#include <bits/stdc++.h>

// Time complexity: O(sqrt(n))
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    int maxLen = 1;
    for (int len = 2; len * (len + 1) / 2 <= n; len++) {
        if ((n - len * (len + 1) / 2) % len == 0) {
            maxLen = len;
        }
    }
    printf("%d", maxLen);
    return 0;
}