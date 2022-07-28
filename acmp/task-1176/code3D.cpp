#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

// Time complexity: O(log(sizeI) * sizeI * sizeJ + nQueries * rangeJ)
// Space complexity: O(log(sizeI) * sizeI * sizeJ)

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

class SparseTable {

private:

    std::vector<std::vector<std::vector<int>>> st;

    std::vector<int> log2;

public:

    SparseTable(int sizeI, int sizeJ, const std::vector<std::vector<int>> &base) {
        st.resize(1, base);
        int lenI = 1;
        for (int logI = 1; 2 * lenI <= sizeI; logI++) {
            st.push_back(st.back());
            for (int i = 0; i + lenI < sizeI; i++) {
                for (int j = 0; j < sizeJ; j++) {
                    st[logI][i][j] = std::min(st[logI][i][j], st[logI][i + lenI][j]);
                }
            }
            lenI <<= 1;
        }
        log2.resize(sizeI + 1);
        for (int i = 2; i <= sizeI; i++) {
            log2[i] = log2[i >> 1] + 1;
        }
    }

    int getMin(int i1, int j1, int i2, int j2) {
        int levelI = log2[i2 - i1 + 1];
        int curMin = INT_MAX;
        for (int j = j1; j <= j2; j++) {
            curMin = std::min({curMin, st[levelI][i1][j], st[levelI][i2 - (1 << levelI) + 1][j]});
        }
        return curMin;
    }
};

int main() {
    int sizeI = nextInt();
    int sizeJ = nextInt();
    int nQueries = nextInt();
    std::vector<std::vector<int>> base(sizeI, std::vector<int>(sizeJ));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            base[i][j] = nextInt();
        }
    }
    SparseTable st(sizeI, sizeJ, base);
    for (int i = 0; i < nQueries; i++) {
        int i1 = nextInt() - 1;
        int j1 = nextInt() - 1;
        int i2 = nextInt() - 1;
        int j2 = nextInt() - 1;
        printf("%d\n", st.getMin(i1, j1, i2, j2));
    }
    return 0;
}