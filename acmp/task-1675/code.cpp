#include <bits/stdc++.h>

// Time complexity: O(log(n))
// Space complexity: O(log(n))

long long getSum(int n, int x1, int x2, std::map<int, int> &memory) {
    long long sum;
    if (memory.find(n) != memory.end()) {
        sum = memory[n];
    } else {
        printf("? %d\n", n);
        fflush(stdout);
        scanf("%lld", &sum);
        memory[n] = sum;
    }
    if (x1 <= n) {
        sum += x1;
    }
    if (x2 <= n) {
        sum += x2;
    }
    return n * (n + 1LL) / 2 - sum;
}

bool addValue(int &x1, int &x2, long long &sum, int val) {
    sum -= val;
    if (x1 == 0) {
        x1 = val;
    } else if (x2 == 0) {
        x2 = val;
        return true;
    }
    return false;
}

int main() {
    std::map<int, int> memory;
    int n;
    scanf("%d", &n);
    int x1 = 0, x2 = 0;
    long long sum = getSum(n, x1, x2, memory);
    int left = 0;
    int right = std::min(1LL * n, sum);
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        long long curSum = getSum(mid, x1, x2, memory);
        if (curSum == sum) {
            right = mid;
        } else if (curSum == 0) {
            left = mid;
        } else if (curSum > mid) {
            if (addValue(x1, x2, sum, sum - curSum)) {
                break;
            }
            right = mid;
        } else {
            if (curSum == 1 || getSum(curSum - 1, x1, x2, memory) == 0) {
                if (addValue(x1, x2, sum, curSum)) {
                    break;
                }
                left = mid;
            } else {
                if (addValue(x1, x2, sum, sum - curSum)) {
                    break;
                }
                right = mid;
            }
        }
    }
    printf("! %d %d %lld\n", x1, x2, sum);
    fflush(stdout);
    return 0;
}