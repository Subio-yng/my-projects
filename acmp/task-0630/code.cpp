#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nTests * (nGuards + range))
// Space complexity: O(nGuards + range)

bool isCorrectTest(const int RANGE) {
    int nGuards;
    scanf("%d", &nGuards);
    std::vector<int> countDiff(RANGE + 1, 0);
    std::vector<int> sumDiff(RANGE + 1, 0);
    for (int i = 0; i < nGuards; i++) {
        int in, out;
        scanf("%d %d", &in, &out);
        countDiff[in]++;
        countDiff[out]--;
        sumDiff[in] += i;
        sumDiff[out] -= i;
    }
    std::vector<bool> isSingle(nGuards, false);
    int curCount = 0;
    int curSum = 0;
    int minCount = RANGE;
    for (int i = 0; i < RANGE; i++) {
        curCount += countDiff[i];
        curSum += sumDiff[i];
        minCount = std::min(minCount, curCount);
        if (curCount == 1) {
            isSingle[curSum] = true;
        }
    }
    if (minCount != 1) {
        return false;
    }
    for (int i = 0; i < nGuards; i++) {
        if (!isSingle[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    const int MAX_TIMELINE = 10000;
    int nTests;
    scanf("%d", &nTests);
    for (int i = 0; i < nTests; i++) {
        if (isCorrectTest(MAX_TIMELINE)) {
            printf("Accepted");
        } else {
            printf("Wrong Answer");
        }
        printf("\n");
    }
    return 0;
}