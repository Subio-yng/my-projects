#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

// Time complexity: O(len^3)
// Space complexity: O(len^2)

bool areBracketsMatches(char left, char right) {
    return left == '(' && right == ')' ||
        left == '[' && right == ']' ||
        left == '{' && right == '}';
}

int main() {
    const int MAX = 101;
    char buf[1 + 100];
    scanf("%s", &buf);
    std::string str(buf);
    int len = (int) str.length();
    std::vector<std::vector<int>> minChanges(len, std::vector<int>(len, MAX));
    for (int iLen = 1; iLen <= len; iLen++) {
        for (int iLeft = 0; iLeft + iLen <= len; iLeft++) {
            int iRight = iLeft + iLen - 1;
            if (iLen == 1) {
                minChanges[iLeft][iRight] = 1;
            } else if (iLen == 2) {
                if (areBracketsMatches(str[iLeft], str[iRight])) {
                    minChanges[iLeft][iRight] = 0;
                } else {
                    minChanges[iLeft][iRight] = 2;
                }
            } else {
                if (areBracketsMatches(str[iLeft], str[iRight])) {
                    minChanges[iLeft][iRight] = std::min(minChanges[iLeft][iRight],
                                                         minChanges[iLeft + 1][iRight - 1]);
                }
                for (int mid = iLeft + 1; mid <= iRight; mid++) {
                    minChanges[iLeft][iRight] = std::min(minChanges[iLeft][iRight],
                                                         minChanges[iLeft][mid - 1] + minChanges[mid][iRight]);

                }
            }
        }
    }
    printf("%d", minChanges[0][len - 1]);
    return 0;
}