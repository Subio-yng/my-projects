#include <bits/stdc++.h>

// Time complexity: O(len(str))
// Space complexity: O(len(str))

bool isEqual(const std::vector<int> &a, int b, int n) {
    int res = 0;
    for (int next : a) {
        res *= n;
        res += next;
        if (res > b) {
            break;
        }
    }
    return res == b;
}

int main() {
    const int MAX_N = 36;
    char buf[1 + 100'000];
    scanf(" %s", &buf);
    std::string str(buf);
    int n = (int) str.length();
    std::vector<int> a(n);
    int maxC = 0;
    for (int i = 0; i < n; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            a[i] = str[i] - '0';
        } else {
            a[i] = 10 + str[i] - 'A';
        }
        maxC = std::max(maxC, a[i]);
    }
    int b;
    scanf("%d", &b);
    for (int n = maxC + 1; n <= MAX_N; n++) {
        if (isEqual(a, b, n)) {
            printf("%d", n);
            return 0;
        }
    }
    printf("0");
    return 0;
}
