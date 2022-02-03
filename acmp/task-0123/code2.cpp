#include <stdio.h>
#include <string>
#include <vector>

// Time complexity: O(len^3)
// Space complexity: O(len^2)

bool areBracketsMatches(char left, char right) {
    return left != ')' && right != '(';
}

int main() {
    char buf[1 + 80];
    scanf("%s", &buf);
    std::string str(buf);
    int len = (int) str.length();
    std::vector<std::vector<int>> ways(len, std::vector<int>(len, 0));
    for (int iLen = 2; iLen <= len; iLen += 2) {
        for (int left = 0; left + iLen <= len; left++) {
            int right = left + iLen - 1;
            if (areBracketsMatches(str[left], str[right])) {
                if (iLen == 2) {
                    ways[left][right] = 1;
                } else {
                    ways[left][right] = ways[left + 1][right - 1];
                    if (areBracketsMatches(str[left], str[left + 1])) {
                        ways[left][right] += ways[left + 2][right];
                    }
                    int left1 = left + 1;
                    for (int right1 = left + 2; right1 <= right - 3; right1 += 2) {
                        int left2 = right1 + 2;
                        int right2 = right;
                        if (areBracketsMatches(str[left], str[right1 + 1])) {
                            ways[left][right] += ways[left1][right1] * ways[left2][right2];
                        }
                    }
                }
            }
        }
    }
    printf("%d", ways[0][len - 1]);
    return 0;
}