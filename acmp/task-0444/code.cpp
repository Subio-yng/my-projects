#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

void printMinStr(int left, int right, const std::vector<int> &a) {
    std::string s1 = std::to_string(a[left]);
    for (int i = left + 1; i <= right; i++) {
        if (a[i] == a[i - 1]) {
            continue;
        }
        s1 += ", " + std::to_string(a[i]);
    }
    std::string s2 = std::to_string(a[left]) + ", ..., " + std::to_string(a[right]);
    if (s1.length() < s2.length()) {
        printf("%s", s1.c_str());
    } else {
        printf("%s", s2.c_str());
    }
    if (right != (int) a.size() - 1) {
        printf(", ");
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
    int left = 0;
    int right = 0;
    while (right < n) {
        while (right + 1 < n && a[right + 1] - a[right] <= 1) {
            right++;
        }
        printMinStr(left, right, a);
        right++;
        left = right;
    }
    return 0;
}