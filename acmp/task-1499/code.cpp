#include <bits/stdc++.h>

// Time complexity: O(log(RANGE))
// Space complexity: O(1)

int main() {
    int left = 0;
    int right = 1'000'000'000;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        printf("? %d\n", mid);
        fflush(stdout);
        int cur;
        scanf("%d", &cur);
        if (cur == mid) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("! %d", right);
    fflush(stdout);
    return 0;
}