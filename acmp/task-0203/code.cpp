#include <stdio.h>
#include <string>
#include <algorithm>

// Time complexity: O(len(n)^2)
// Space complexity: O(buf)

int main() {
    char buf[1 + 10000];
    scanf("%s", &buf);
    std::string str1(buf);
    scanf(" %s", &buf);
    std::string str2(buf);
    for (int i = 0; i < (int) str2.length(); i++) {
        if (str2 == str1) {
            printf("%d", i);
            return 0;
        }
        str2.push_back(str2[0]);
        std::reverse(str2.begin(), str2.end());
        str2.pop_back();
        std::reverse(str2.begin(), str2.end());
    }
    printf("-1");
    return 0;
}