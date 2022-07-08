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

int main() {
    int n = nextInt();
    std::vector<std::vector<int>> st(1, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        st[0][i] = nextInt();
    }
    int len = 1;
    for (int i = 1; len * 2 <= n; i++) {
        st.push_back(st.back());
        for (int j = 0; j + len < n; j++) {
            st[i][j] = std::min(st[i][j], st[i][j + len]);
        }
        len *= 2;
    }
    std::vector<int> log2(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i >> 1] + 1;
    }
    int q = nextInt();
    for (int i = 0; i < q; i++) {
        int left = nextInt() - 1;
        int right = nextInt() - 1;
        int len = right - left + 1;
        int level = log2[len];
        printf("%d ", std::min(st[level][left], st[level][right - (1 << level) + 1]));
    }
    return 0;
}