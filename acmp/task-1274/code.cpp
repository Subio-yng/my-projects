#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n, sum;
    scanf("%d %d", &n, &sum);
    std::vector<int> price(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    long long maxSum = 0;
    long long minSum = LLONG_MAX;
    int maxPrice = price[n - 1];
    int minPrice = price[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        maxSum = std::max(maxSum, 1LL * sum / price[i] * maxPrice + sum % price[i]);
        minSum = std::min(minSum, 1LL * sum / price[i] * minPrice + sum % price[i]);
        maxPrice = std::max(maxPrice, price[i]);
        minPrice = std::min(minPrice, price[i]);
    }
    printf("%lld %lld", minSum, maxSum);
    return 0;
}