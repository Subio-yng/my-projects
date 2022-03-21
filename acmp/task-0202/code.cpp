#include <stdio.h>
#include <vector>
#include <string>
 
// Time complexity: O(len1 + len2)
// Space complexity: O(len1 + len2)
 
std::vector<int> getPrefixFunction(std::string sample) {
    std::vector<int> p((int) sample.size(), 0);
    for (int i = 1; i < sample.length(); i++) {
        int prev = p[i - 1];
        while (prev > 0 && sample[i] != sample[prev]) {
            prev = p[prev - 1];
        }
        if (sample[i] == sample[prev]) {
            prev++;
        }
        p[i] = prev;
    }
    return p;
}
 
int main() {
    char buf[1 + 50000];
    scanf("%s", &buf);
    std::string str1(buf);
    scanf("%s", &buf);
    std::string str2(buf);
    int len2 = (int) str2.length();
    std::vector<int> prefixStr = getPrefixFunction(str2 + '$' + str1);
    for (int i = len2; i < (int) prefixStr.size(); i++) {
        if (prefixStr[i] == len2) {
            printf("%d ", i - len2 * 2);
        }
    }
    return 0;
}