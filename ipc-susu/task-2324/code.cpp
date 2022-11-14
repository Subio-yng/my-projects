#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

struct Cell {

    int val;

    int id;
};

int main() {
    const int MOD = 1'000'000;
    int n;
    scanf("%d", &n);
    std::vector<Cell> prefSum(n + 1);
    prefSum[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        prefSum[i] = {(prefSum[i - 1].val + val) % MOD, i};
    }
    std::sort(prefSum.begin(), prefSum.end(), [](const Cell &left, const Cell &right) {
        if (left.val == right.val) {
            return left.id < right.id;
        }
        return left.val < right.val;
    });
    const int UNDEF = -1;
    int minDist = n + 1;
    int start = UNDEF;
    for (int i = 1; i <= n; i++) {
        if (prefSum[i].val == prefSum[i - 1].val) {
            int curDist = prefSum[i].id - prefSum[i - 1].id;
            if (minDist > curDist ||
                minDist == curDist && start > prefSum[i - 1].id
                ) {
                minDist = curDist;
                start = prefSum[i - 1].id;
            }
        }
    }
    if (start == UNDEF) {
        printf("-1");
    } else {
        printf("%d %d", minDist, start + 1);
    }
    return 0;
}