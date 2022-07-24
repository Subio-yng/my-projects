#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nTests * (nGuards + range * log(range)))
// Space complexity: O(nGuards + range * log(range))

const int MAX_TIMELINE = 10000;

class SparseTable {

private:

    std::vector<std::vector<int>> st;

    std::vector<int> log2;

public:

    SparseTable() {
        st.resize(1, std::vector<int>(MAX_TIMELINE + 1, 0));
        for (int len = 1; 2 * len <= MAX_TIMELINE + 1; len <<= 1) {
            st.push_back(std::vector<int>(MAX_TIMELINE + 1, 0));
        }
        log2.resize(MAX_TIMELINE + 2, 0);
        for (int i = 2; i <= MAX_TIMELINE + 1; i++) {
            log2[i] = log2[i >> 1] + 1;
        }
    }

    void buildSparseTable(const std::vector<int> &base) {
        int curCountGuards = 0;
        for (int i = 0; i <= MAX_TIMELINE; i++) {
            st[0][i] = curCountGuards;
            curCountGuards += base[i];
        }
        int len = 1;
        for (int i = 1; 2 * len <= MAX_TIMELINE + 1; i++) {
            for (int j = 0; j + len <= MAX_TIMELINE; j++) {
                st[i][j] = std::min(st[i - 1][j], st[i - 1][j + len]);
            }
            len <<= 1;
        }
    }

    int getMin(int qLeft, int qRight) {
        int level = log2[qRight - qLeft + 1];
        return std::min(st[level][qLeft], st[level][qRight - (1 << level) + 1]);
    }
};

SparseTable st;

struct Gap {

    int in;

    int out;

    static Gap read() {
        int in, out;
        scanf("%d %d", &in, &out);
        return {in, out};
    }
};

bool solve() {
    int nGuards;
    scanf("%d", &nGuards);
    std::vector<Gap> guards(nGuards);
    std::vector<int> curLine(MAX_TIMELINE + 1, 0);
    for (int i = 0; i < nGuards; i++) {
        guards[i] = Gap::read();
        curLine[guards[i].in]++;
        curLine[guards[i].out]--;
    }
    st.buildSparseTable(curLine);
    if (st.getMin(1, MAX_TIMELINE) == 0) {
        return false;
    }
    for (int i = 0; i < nGuards; i++) {
        if (st.getMin(guards[i].in + 1, guards[i].out) > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int nTests;
    scanf("%d", &nTests);
    for (int i = 0; i < nTests; i++) {
        if (solve()) {
            printf("Accepted");
        } else {
            printf("Wrong Answer");
        }
        printf("\n");
    }
    return 0;
}