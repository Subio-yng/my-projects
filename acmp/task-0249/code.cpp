#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

// Time complexity: O(len^3)
// Space complexity: O(len^2)

bool areBracketsMathces(char l, char r) {
    return l == '(' && r == ')' ||
        l == '[' && r == ']' ||
        l == '{' && r == '}';
}

int main() {
    const int MAX = 101;
    char buf[1 + 100];
    scanf("%s", &buf);
    std::string str(buf);
    int len = (int) str.length();
    std::vector<std::vector<int>> change(len, std::vector<int>(len, MAX));
    for (int iLen = 1; iLen <= len; iLen++) {
        for (int iLeft = 0; iLeft + iLen <= len; iLeft++) {
            int iRight = iLeft + iLen - 1;
            if (iLen == 1) {
                change[iLeft][iRight] = 1;
            } else if (iLen == 2) {
                if (areBracketsMathces(str[iLeft], str[iRight])) {
                    change[iLeft][iRight] = 0;
                } else {
                    change[iLeft][iRight] = 2;
                }
            } else {
                if (areBracketsMathces(str[iLeft], str[iRight])) {
                    change[iLeft][iRight] = std::min(change[iLeft][iRight],
                                                     change[iLeft + 1][iRight - 1]);
                }
                for (int iLeft1 = iLeft + 1; iLeft1 <= iRight; iLeft1++) {
                    change[iLeft][iRight] = std::min(change[iLeft][iRight],
                                                     change[iLeft][iLeft1 - 1] + change[iLeft1][iRight]);

                }
            }
        }
    }
    printf("%d", change[0][len - 1]);
    return 0;
}