#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

void printMinStr(std::string &s1, std::string &s2) {
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
    a.push_back(a.back() + 2);
    std::string s1;
    std::string s2;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) {
            continue;
        }
        std::string cur;
        if (i == 0) {
            cur = std::to_string(a[i]);
        } else {
            cur = ", " + std::to_string(a[i]);
        }
        s1 += cur;
        if (s2.empty()) {
            s2 += cur;
        }
        if (a[i] + 1 != a[i + 1]) {
            s2 += ", ..." + cur;
            printMinStr(s1, s2);
            s1.clear();
            s2.clear();
        }
    }
    printMinStr(s1, s2);
    return 0;
}