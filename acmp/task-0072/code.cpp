#include <stdio.h>
#include <algorithm>
#include <string>

// Time complexity: O(len)
// Space complexity: O(len)

int main() {
    char buf[1 + 80];
    scanf("%s", &buf);
    std::string str(buf);
    std::next_permutation(str.begin(), str.end());
    printf("%s", str.c_str());
    return 0;
}