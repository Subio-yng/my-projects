#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    const int INF = 30'000;
    int n;
    scanf("%d", &n);
    int bestLeft = -INF;
    int bestRight = INF;
    int left;
    scanf("%d", &left);
    for (int i = 1; i < n; i++) {
        int right;
        scanf("%d", &right);
        if (right - left < bestRight - bestLeft) {
            bestRight = right;
            bestLeft = left;
        }
        left = right;
    }
    printf("%d %d", bestLeft, bestRight);
    return 0;
}