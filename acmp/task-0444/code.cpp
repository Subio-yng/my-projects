#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

void printMinStr(const std::string &s1, const std::string &s2) {
    if (s1.length() < s2.length()) {
        printf("%s", s1.c_str());
    } else {
        printf("%s", s2.c_str());
    }
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end());
    std::string s1 = std::to_string(a[0]);
    std::string s2 = std::to_string(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            continue;
        }
        std::string cur = ", " + std::to_string(a[i]);
        if (a[i - 1] + 1 != a[i]) {
            printMinStr(s1, s2 + ", ..., " + std::to_string(a[i - 1]));
            s1 = cur;
            std::swap(s2, cur);
        } else {
            s1 += cur;
        }
    }
    printMinStr(s1, s2 + ", ..., " + std::to_string(a.back()));
    return 0;
}