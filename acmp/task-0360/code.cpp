#include <stdio.h>
#include <algorithm>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

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
    std::vector<std::vector<short int>> table(n, std::vector<short int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            table[i][j] = nextInt();
        }
    }
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 3 vertical elements
            if (i + 2 < n) {
                maxSum = std::max(maxSum, table[i][j] + table[i + 1][j] + table[i + 2][j]);
            }
            // 3 horizontal elements
            if (j + 2 < n) {
                maxSum = std::max(maxSum, table[i][j] + table[i][j + 1] + table[i][j + 2]);
            }
            // triangles left_up
            if (i > 0 && j > 0) {
                maxSum = std::max(maxSum, table[i][j] + std::max(table[i - 1][j], table[i][j - 1]) + table[i - 1][j - 1]);
            }
            // triangles right_up
            if (i > 0 && j + 1 < n) {
                maxSum = std::max(maxSum, table[i][j] + std::max(table[i - 1][j], table[i][j + 1]) + table[i - 1][j + 1]);
            }
            // triangles left_down
            if (i + 1 < n && j > 0) {
                maxSum = std::max(maxSum, table[i][j] + std::max(table[i][j - 1], table[i + 1][j]) + table[i + 1][j - 1]);
            }
            // triangles right_down
            if (i + 1 < n && j + 1 < n) {
                maxSum = std::max(maxSum, table[i][j] + std::max(table[i + 1][j], table[i][j + 1]) + table[i + 1][j + 1]);
            }
        }
    }
    printf("%d", maxSum);
    return 0;
}