#include <stdio.h>
#include <vector>
#include <string>

// Time complexity: O(len)
// Space complexity: O(len)

std::vector<int> getPrefixFunction(std::string sample) {
    int len = (int) sample.length();
    std::vector<int> p(len, 0);
    for (int i = 1; i < len; i++) {
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
    char buf[1 + 1000000];
    scanf("%s", &buf);
    std::vector<int> ans = getPrefixFunction(buf);
    for (int i = 0; i < (int) ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}