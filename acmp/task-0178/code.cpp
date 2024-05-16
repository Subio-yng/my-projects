#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    std::unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    int maxCnt = 0;
    int val = 0;
    for (auto [nextVal, nextCnt] : cnt) {
        if (nextCnt > maxCnt || nextCnt == maxCnt && nextVal < val) {
            maxCnt = nextCnt;
            val = nextVal;
        }
    }
    for (int next : a) {
        if (next != val) {
            printf("%d ", next);
        }
    }
    for (int i = 0; i < maxCnt; i++) {
        printf("%d ", val);
    }
    return 0;
}