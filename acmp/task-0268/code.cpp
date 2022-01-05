#include <stdio.h>
#include <vector>

// Time complexity: O(len^2)
// Space complexity: O(len)

int main() {
    int len, change;
    scanf("%d %d", &len, &change);
    char str[1 + 5000];
    scanf(" %s", &str);
    std::vector<int> curSubstr(len);
    std::vector<int> prevSubstr(len);
    std::vector<int> prevPrevSubstr(len, 0);
    int sumSubstrs = 0;
    for (int iLen = 1; iLen <= len; iLen++) {
        for (int iLeft = 0; iLeft + iLen <= len; iLeft++) {
            int iRight = iLeft + iLen - 1;
            if (iLen == 1) {
                curSubstr[iLeft] = 0;
            } else if (str[iLeft] != str[iRight]) {
                curSubstr[iLeft] = prevPrevSubstr[iLeft + 1] + 1;
            } else {
                curSubstr[iLeft] = prevPrevSubstr[iLeft + 1];
            }
            if (curSubstr[iLeft] <= change) {
                sumSubstrs++;
            }
        }
        prevPrevSubstr = prevSubstr;
        prevSubstr = curSubstr;
    }
    printf("%d", sumSubstrs);
    return 0;
}