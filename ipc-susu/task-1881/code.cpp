#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &diff[i]);
    }
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        diff[i] -= val;
    }
    std::vector<bool> isStart(n, true);
    int curSum = 0;
    for (int j = 0; j < 2; j++) {
        for (int i = n - 1; i >= 0; i--) {
            curSum += diff[i];
            if (curSum < 0) {
                isStart[i] = false;
            } else {
                curSum = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (isStart[i]) {
            printf("%d ", i + 1);
        }
    }
    return 0;
}