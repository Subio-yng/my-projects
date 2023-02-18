#include <bits/stdc++.h>

// Time complexity: O(nQ * log(n))
// Space complexity: O(1)

long long getMaxRoom(long long n, int k, int x, int y) {
    return n / k * x + (n - n / k) * y;
}

int getFloor(int n, int k, int x, int y, long long cur) {
    cur = (cur - 1) % getMaxRoom(n, k, x, y) + 1;
    int left = 0;
    int right = n;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (getMaxRoom(mid, k, x, y) >= cur) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

int main() {
    int n, k, x, y;
    scanf("%d %d %d %d", &n, &k, &x, &y);
    int nQ;
    scanf("%d", &nQ);
    for (int i = 0; i < nQ; i++) {
        long long cur;
        scanf("%lld", &cur);
        printf("%d\n", getFloor(n, k, x, y, cur));
    }
    return 0;
}