#include <stdio.h>
#include <string>

// Time complexity: O(n * len(ans))
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    n = n * (n - 1) >> 1;
    std::string ans = "3";
    for (int i = 1; i < n; i++) {
        int remainder = 0;
        for (int j = 0; j < (int) ans.length(); j++) {
            ans[j] -= '0';
            ans[j] *= 3;
            ans[j] += '0' + remainder;
            remainder = 0;
            if (ans[j] > '9') {
                remainder = (ans[j] - '0') / 10;
                ans[j] = (ans[j] - '0') % 10 + '0';
            }
        }
        if (remainder > 0) {
            ans += remainder + '0';
        }
    }
    std::reverse(ans.begin(), ans.end());
    printf("%s", ans.c_str());
    return 0;
}