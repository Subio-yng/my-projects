#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n * log(n) + q)
// Space complexity: O(n * log(n))

int nextChar() {
    static char buffer[1 << 16];
    static int pos = 0;
    static int size = 0;
    if (pos >= size) {
        size = (int) fread(buffer, sizeof(buffer[0]), sizeof(buffer) / sizeof(buffer[0]), stdin);
        pos = 0;
        if (pos >= size) {
            return EOF;
        }
    }
    int res = buffer[pos] & 0xFF;
    pos++;
    return res;
}

int nextInt() {
    int c = nextChar();
    while (0 <= c && c <= ' ') {
        c = nextChar();
    }
    int coef = 1;
    if (c == '-') {
        coef = -1;
        c = nextChar();
    }
    int n = c - '0';
    c = nextChar();
    while ('0' <= c && c <= '9') {
        int d = c - '0';
        c = nextChar();
        n = n * 10 + d;
    }
    return n * coef;
}

int getLog(int n) {
    int res = 0;
    while (n > 1) {
        res++;
        n /= 2;
    }
    return res;
}

int main() {
    int n = nextInt();
    std::vector<std::vector<int>> st(n, std::vector<int>(getLog(n) + 1));
    for (int i = 0; i < n; i++) {
        st[i][0] = nextInt();
    }
    for (int len = 1; (1 << len) <= n; len++) {
        for (int i = 0; i + (1 << len) <= n; i++) {
            st[i][len] = std::min(st[i][len - 1], st[i + (1 << (len - 1))][len - 1]);
        }
    }
    int q = nextInt();
    for (int i = 0; i < q; i++) {
        int left = nextInt() - 1;
        int right = nextInt() - 1;
        int curLog = getLog(right - left + 1);
        printf("%d ", std::min(st[left][curLog], st[right - (1 << curLog) + 1][curLog]));
    }
    return 0;
}