#include <bits/stdc++.h>

// Time complexity: O(n^2)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> order(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &order[i]);
    }
    int maxSum = 0;
    int bestI = 0;
    for (int i = 0; i < n; i++) {
        int curSum = 0;
        for (int j = 0; j < n; j++) {
            curSum += std::max(0, order[j] - abs(i - j));
        }
        if (curSum > maxSum) {
            maxSum = curSum;
            bestI = i;
        }
    }
    printf("%d %d", maxSum, bestI + 1);
    return 0;
}