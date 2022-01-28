#include <stdio.h>
#include <string>
#include <vector>

// Time complexity: O(len^3)
// Space complexity: O(len^3)

bool areBracketsMatches(char left, char right) {
    return left == '(' && right == ')' ||
        left == '[' && right == ']' ||
        left == '{' && right == '}';
}

std::string getPairBrackets(char type) {
    if (type == '(' || type == ')') {
        return "()";
    }
    if (type == '[' || type == ']') {
        return "[]";
    }
    return "{}";
}

int main() {
    char buf[1 + 100];
    scanf("%100s", &buf);
    if (buf == "") {
        return 0;
    }
    std::string str(buf);
    int len = (int) str.length();
    std::vector<std::vector<std::string>> ans(len, std::vector<std::string>(len));
    for (int iLen = 1; iLen <= len; iLen++) {
        for (int iLeft = 0; iLeft + iLen <= len; iLeft++) {
            int iRight = iLeft + iLen - 1;
            if (iLen == 1) {
                ans[iLeft][iRight] = getPairBrackets(str[iLeft]);
            } else if (iLen == 2) {
                ans[iLeft][iRight] = getPairBrackets(str[iLeft]);
                if (!areBracketsMatches(str[iLeft], str[iRight])) {
                    ans[iLeft][iRight] += getPairBrackets(str[iRight]);
                }
            } else {
                if (areBracketsMatches(str[iLeft], str[iRight])) {
                    ans[iLeft][iRight] = str[iLeft] + ans[iLeft + 1][iRight - 1] + str[iRight];
                }
                for (int mid = iLeft + 1; mid <= iRight; mid++) {
                    if (ans[iLeft][iRight].empty() ||
                        ans[iLeft][iRight].length() > (ans[iLeft][mid - 1] + ans[mid][iRight]).length()
                        ) {
                        ans[iLeft][iRight] = ans[iLeft][mid - 1] + ans[mid][iRight];
                    }
                }
            }
        }
    }
    printf("%s", ans[0][len - 1].c_str());
    return 0;
}