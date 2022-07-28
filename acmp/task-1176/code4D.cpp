#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(log(sizeI) * log(sizeJ) * sizeI * sizeJ + nQueries)
// Space complexity: O(log(sizeI) * log(sizeJ) * sizeI * sizeJ)

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

    std::vector<std::vector<std::vector<std::vector<int>>>> st;

    std::vector<int> log2;

public:

    SparseTable(int sizeI, int sizeJ, const std::vector<std::vector<int>> &base) {
        st.resize(1, std::vector<std::vector<std::vector<int>>>(1, base));
        int lenJ = 1;
        for (int logJ = 1; 2 * lenJ <= sizeJ; logJ++) {
            st[0].push_back(st[0].back());
            for (int i = 0; i < sizeI; i++) {
                for (int j = 0; j + lenJ < sizeJ; j++) {
                    st[0][logJ][i][j] = std::min(st[0][logJ][i][j], st[0][logJ][i][j + lenJ]);
                }
            }
            lenJ <<= 1;
        }
        int lenI = 1;
        for (int logI = 1; 2 * lenI <= sizeI; logI++) {
            st.push_back(st.back());
            for (int i = 0; i + lenI < sizeI; i++) {
                for (int j = 0; j < sizeJ; j++) {
                    st[logI][0][i][j] = std::min(st[logI][0][i][j], st[logI][0][i + lenI][j]);
                }
                lenJ = 1;
                for (int logJ = 1; 2 * lenJ <= sizeJ; logJ++) {
                    for (int j = 0; j < sizeJ; j++) {
                        st[logI][logJ][i][j] = std::min(st[logI][logJ][i][j], st[logI][logJ][i + lenI][j]);
                    }
                    lenJ <<= 1;
                }
            }
            lenI <<= 1;
        }
        int logSize = std::max(sizeI, sizeJ);
        log2.resize(logSize + 1);
        for (int i = 2; i <= logSize; i++) {
            log2[i] = log2[i >> 1] + 1;
        }
    }

    int getMin(int i1, int j1, int i2, int j2) {
        int levelI = log2[i2 - i1 + 1];
        int levelJ = log2[j2 - j1 + 1];
        int lenI = (1 << levelI) - 1;
        int lenJ = (1 << levelJ) - 1;
        return std::min({st[levelI][levelJ][i1][j1], st[levelI][levelJ][i1][j2 - lenJ],
            st[levelI][levelJ][i2 - lenI][j1], st[levelI][levelJ][i2 - lenI][j2 - lenJ]});
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