#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
    int n, nP;
    scanf("%d %d", &n, &nP);
    std::vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }
    std::sort(cost.rbegin(), cost.rend());
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += cost[i] * (i / nP + 1);
    }
    printf("%lld", sum);
    return 0;
}