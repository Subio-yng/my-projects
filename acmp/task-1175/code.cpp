#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O((n + q) * log(n))
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
    int logN = getLog(n);
    std::vector<std::vector<int>> st(n, std::vector<int>(logN + 1));
    for (int i = 0; i < n; i++) {
        st[i][0] = nextInt();
    }
    for (int j = 1; j <= logN; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = std::min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    int q = nextInt();
    for (int i = 0; i < q; i++) {
        int left = nextInt() - 1;
        int right = nextInt() - 1;
        int curMin = st[right][0];
        for (int j = logN; j >= 0; j--) {
            if ((1 << j) <= right - left + 1) {
                curMin = std::min(curMin, st[left][j]);
                left += 1 << j;
            }
        }
        printf("%d ", curMin);
    }
    return 0;
}