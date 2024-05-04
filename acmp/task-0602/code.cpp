#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end());
    int bestLeft = a.front();
    int bestRight = a.back();
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] < bestRight - bestLeft) {
            bestRight = a[i];
            bestLeft = a[i - 1];
        }
    }
    printf("%d %d", bestLeft, bestRight);
    return 0;
}