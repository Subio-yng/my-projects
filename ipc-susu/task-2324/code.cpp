#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    const int MOD = 1'000'000;
    const int UNDEF = -1;
    int n;
    scanf("%d", &n);
    int start = UNDEF;
    int minDist = n + 1;
    std::vector<int> pos(MOD, UNDEF);
    pos[0] = 0;
    int curSum = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        curSum = (curSum + val) % MOD;
        if (pos[curSum] != UNDEF) {
            int curDist = i - pos[curSum];
            if (curDist < minDist) {
                minDist = curDist;
                start = pos[curSum];
            }
        }
        pos[curSum] = i;
    }
    if (start == UNDEF) {
        printf("-1");
    } else {
        printf("%d %d", minDist, start + 1);
    }
    return 0;
}