#include <stdio.h>
#include <vector>
#include <climits>

// Time complexity: O(n * RANGE)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    const int RANGE = 1000;
    int minDiff = INT_MAX;
    for (int c = -RANGE; c <= RANGE; c++) {
        int curDiff = 0;
        for (int i = 0; i < n; i++) {
            curDiff += abs(a[i] + c - b[i]);
        }
        minDiff = std::min(minDiff, curDiff);
    }
    printf("%d", minDiff);
    return 0;
}