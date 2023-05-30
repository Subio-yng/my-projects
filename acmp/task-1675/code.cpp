#include <bits/stdc++.h>

// Time complexity: O(log(n))
// Space complexity: O(1)

long long getSum(int n) {
    printf("? %d\n", n);
    fflush(stdout);
    long long sum;
    scanf("%lld", &sum);
    return n * (n + 1LL) / 2 - sum;
}

int main() {
    int n;
    scanf("%d", &n);
    long long sum = getSum(n);
    int left = 2;
    int right = std::min(1LL * n, sum);
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        long long curSum = getSum(mid);
        if (curSum < sum) {
            left = mid;
        } else {
            right = mid;
        }
    }
    int x1 = right;
    int x2 = getSum((sum - x1) / 2);
    int x3 = sum - x1 - x2;
    printf("! %d %d %d", x1, x2, x3);
    return 0;
}