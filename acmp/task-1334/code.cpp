#include <stdio.h>
#include <algorithm>
#include <vector>

// Time complexity: O(len^3)
// Space complexity: O(len^2)

int main() {
    const int MAX_COST = 1000 * 1000 * 1000 + 1;
    int len;
    scanf("%d", &len);
    std::vector<int> list(len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &list[i]);
    }
    std::vector<std::vector<int>> minCost(len, std::vector<int>(len));
    for (int iLen = 2; iLen <= len; iLen++) {
        for (int iLeft = 0; iLeft + iLen <= len; iLeft++) {
            int iRight = iLeft + iLen - 1;
            if (iLen == 2) {
                minCost[iLeft][iRight] = 0;
            } else {
                minCost[iLeft][iRight] = MAX_COST;
                for (int iMid = iLeft + 1; iMid < iRight; iMid++) {
                    minCost[iLeft][iRight] = std::min(
                        minCost[iLeft][iRight],
                        list[iMid] * list[iLeft] * list[iRight] + minCost[iLeft][iMid] + minCost[iMid][iRight]);
                }
            }
        }
    }
    printf("%d", minCost[0][len - 1]);
    return 0;
}