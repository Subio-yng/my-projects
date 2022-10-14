#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nPack * log(range))
// Space complexity: O(nPack)

bool canDone(int minutes, int nPack, int nMate, int speed, const std::vector<int> &prefSum) {
    int last = 0;
    int countMate = 0;
    long long maxT = 1LL * minutes * speed;
    for (int i = 1; i <= nPack; i++) {
        if (prefSum[i] - prefSum[last] > 1LL * minutes * speed) {
            maxT = std::max(maxT, 1LL * prefSum[i - 1] - prefSum[last]);
            countMate++;
            last = i - 1;
        }
    }
    if (last != nPack) {
        maxT = std::max(maxT, 1LL * prefSum.back() - prefSum[last]);
        countMate++;
    }
    return countMate <= nMate && maxT == 1LL * minutes * speed;
}

int main() {
    int nPack, nMate, speed;
    scanf("%d %d %d", &nPack, &nMate, &speed);
    std::vector<int> prefSum(nPack + 1, 0);
    for (int i = 1; i <= nPack; i++) {
        scanf("%d", &prefSum[i]);
        prefSum[i] += prefSum[i - 1];
    }
    int leftT = 0;
    int rightT = prefSum.back();
    while (leftT + 1 < rightT) {
        int midT = (leftT + rightT) / 2;
        if (canDone(midT, nPack, nMate, speed, prefSum)) {
            rightT = midT;
        } else {
            leftT = midT;
        }
    }
    printf("%d", rightT);
    return 0;
}