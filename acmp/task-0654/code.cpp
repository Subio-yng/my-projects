#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    int curMax;
    scanf("%d", &curMax);
    int prev = curMax;
    long long cnt = 0;
    for (int i = 1; i < n; i++) {
        int cur;
        scanf("%d", &cur);
        if (curMax < cur) {
            cnt += cur - curMax;
            curMax = cur;
        } else if (cur < prev) {
            cnt += prev - cur;
        }
        prev = cur;
    }
    printf("%lld", cnt);
    return 0;
}