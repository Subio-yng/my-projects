#include <bits/stdc++.h>

// Time complexity: O(len)
// Space complexity: O(len)

std::vector<int> getZFunction(const std::string &str, int n) {
    std::vector<int> z(n, 0);
    int left = 0;
    int right = 0;
    for (int i = 1; i < n; i++) {
        if (i <= right) {
            z[i] = std::min(right - i + 1, z[i - left]);
        }
        while (z[i] + i < n && str[z[i]] == str[z[i] + i]) {
            z[i]++;
        }
        if (z[i] + i - 1 > right) {
            left = i;
            right = z[i] + i - 1;
        }
    }
    return z;
}

int main() {
    char buf[1 + 1'000'000];
    scanf(" %s", &buf);
    std::string str(buf);
    int len = (int) str.length();
    std::vector<int> z = getZFunction(str, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", z[i]);
    }
    return 0;
}