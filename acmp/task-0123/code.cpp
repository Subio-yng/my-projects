#include <stdio.h>
#include <string>
#include <vector>

// Time complexity: O(len^2)
// Space complexity: O(len^2)

int main() {
    char buf[1 + 80];
    scanf("%s", &buf);
    std::string str(buf);
    int len = (int) str.length();
    str = ' ' + str;
    std::vector<std::vector<int>> ways(len + 1, std::vector<int>(len + 1, 0));
    ways[0][0] = 1;
    for (int iLen = 1; iLen <= len; iLen++) {
        for (int open = 0; open <= len; open++) {
            if (open > 0 && str[iLen] != ')') {
                ways[iLen][open] += ways[iLen - 1][open - 1];
            }
            if (open < len && str[iLen] != '(') {
                ways[iLen][open] += ways[iLen - 1][open + 1];
            }
        }
    }
    printf("%d", ways[len][0]);
    return 0;
}