#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(sizeI^2 * sizeJ^2)
// Space complexity: O(sizeI * sizeJ)

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
    int sizeI = nextInt();
    int sizeJ = nextInt();
    std::vector<std::vector<int>> prefixSum(sizeI + 1, std::vector<int>(sizeJ + 1, 0));
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            prefixSum[i][j] = nextInt() + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }
    int maxSum = prefixSum[1][1];
    for (int i1 = 1; i1 <= sizeI; i1++) {
        for (int j1 = 1; j1 <= sizeJ; j1++) {
            for (int i2 = i1; i2 <= sizeI; i2++) {
                for (int j2 = j1; j2 <= sizeJ; j2++) {
                    int curSum = prefixSum[i2][j2] - prefixSum[i2][j1 - 1] - prefixSum[i1 - 1][j2] + prefixSum[i1 - 1][j1 - 1];
                    maxSum = std::max(maxSum, curSum);
                }
            }
        }
    }
    printf("%d", maxSum);
    return 0;
}