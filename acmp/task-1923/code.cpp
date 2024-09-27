#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

bool canChoose(long long diff, long long prize, const std::vector<long long> &olimp) {
    long long sum = 0;
    long long cost = 1;
    for (long long next : olimp) {
        sum += next * cost;
        if (sum > prize || next > prize / cost) {
            return false;
        }
        cost += diff;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<long long> olimp(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &olimp[i]);
    }
    std::reverse(olimp.begin(), olimp.end());
    long long prize;
    scanf("%lld", &prize);
    long long left = 0;
    long long right = prize;
    while (left + 1 < right) {
        long long mid = (left + right) / 2;
        if (canChoose(mid, prize, olimp)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%lld", left);
    return 0;
}