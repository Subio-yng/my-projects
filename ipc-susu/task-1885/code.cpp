#include <bits/stdc++.h>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

int main() {
    const int MOD = 1'000'000'000 + 9;
    char buf[1 + 100];
    scanf(" %s", &buf);
    std::string str(buf);
    int len = (int) str.length();
    std::vector<std::vector<char>> isPalindrome(len, std::vector<char>(len, true));
    for (int iLen = 2; iLen <= len; iLen++) {
        for (int iLeft = 0; iLeft + iLen <= len; iLeft++) {
            int iRight = iLeft + iLen - 1;
            isPalindrome[iLeft][iRight] = str[iLeft] == str[iRight] && isPalindrome[iLeft + 1][iRight - 1];
        }
    }
    std::vector<int> cnt(len + 1, 1);
    for (int right = 2; right <= len; right++) {
        cnt[right] = cnt[right - 1];
        for (int left = 1; left < right; left++) {
            if (isPalindrome[left - 1][right - 1]) {
                cnt[right] = (cnt[right] + cnt[left - 1]) % MOD;
            }
        }
    }
    printf("%d", cnt[len]);
    return 0;
}