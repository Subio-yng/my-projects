#include <stdio.h>
#include <string>
#include <algorithm>

// Time complexity: O(len!)
// Space complexity: O(len)

int main() {
    char buf[1 + 8];
    scanf("%s", &buf);
    std::string str(buf);
    std::sort(str.begin(), str.end());
    printf("%s", str.c_str());
    while (std::next_permutation(str.begin(), str.end())) {
        printf("\n%s", str.c_str());
    }
    return 0;
}