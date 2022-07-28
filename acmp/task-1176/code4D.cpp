#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(log(sizeI) * sizeI * log(sizeJ) * sizeJ + nQueries)
// Space complexity: O(log(sizeI) * sizeI * log(sizeJ) * sizeJ)

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
    int nQueries = nextInt();
    std::vector<std::vector<std::vector<std::vector<int>>>> st
    (1, std::vector<std::vector<std::vector<int>>>(sizeI, std::vector<std::vector<int>>(1, std::vector<int>(sizeJ))));
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ; j++) {
            st[0][i][0][j] = nextInt();
        }
        int lenJ = 1;
        for (int logJ = 1; 2 * lenJ <= sizeJ; logJ++) {
            st[0][i].push_back(st[0][i].back());
            for (int j = 0; j + lenJ < sizeJ; j++) {
                st[0][i][logJ][j] = std::min(st[0][i][logJ][j], st[0][i][logJ][j + lenJ]);
            }
            lenJ <<= 1;
        }
    }
    int lenI = 1;
    for (int logI = 1; 2 * lenI <= sizeI; logI++) {
        st.push_back(st.back());
        for (int i = 0; i + lenI < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                st[logI][i][0][j] = std::min(st[logI][i][0][j], st[logI][i + lenI][0][j]);
            }
            int lenJ = 1;
            for (int logJ = 1; 2 * lenJ <= sizeJ; logJ++) {
                for (int j = 0; j < sizeJ; j++) {
                    st[logI][i][logJ][j] = std::min({st[logI][i][logJ][j], st[logI][i + lenI][logJ][j]});
                }
                lenJ <<= 1;
            }
        }
        lenI <<= 1;
    }
    std::vector<int> iLog2(sizeI + 1, 0);
    for (int i = 2; i <= sizeI; i++) {
        iLog2[i] = iLog2[i >> 1] + 1;
    }
    std::vector<int> jLog2(sizeJ + 1, 0);
    for (int j = 2; j <= sizeJ; j++) {
        jLog2[j] = jLog2[j >> 1] + 1;
    }
    for (int i = 0; i < nQueries; i++) {
        int i1 = nextInt() - 1;
        int j1 = nextInt() - 1;
        int i2 = nextInt() - 1;
        int j2 = nextInt() - 1;
        int levelI = iLog2[i2 - i1 + 1];
        int levelJ = jLog2[j2 - j1 + 1];
        int min1 = std::min(st[levelI][i1][levelJ][j1], st[levelI][i1][levelJ][j2 - (1 << levelJ) + 1]);
        int min2 = std::min(st[levelI][i2 - (1 << levelI) + 1][levelJ][j1], st[levelI][i2 - (1 << levelI) + 1][levelJ][j2 - (1 << levelJ) + 1]);
        printf("%d\n", std::min(min1, min2));
    }
    return 0;
}