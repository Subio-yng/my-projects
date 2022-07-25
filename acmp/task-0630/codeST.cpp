#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nTests * (nGuards + range * log(range)))
// Space complexity: O(nGuards + range * log(range))

class SparseTable {

private:

    std::vector<std::vector<int>> st;

    std::vector<int> log2;

public:

    SparseTable(int size, const std::vector<int> &base) {
        st.push_back(base);
        int len = 1;
        for (int i = 1; 2 * len <= size; i++) {
            st.push_back(st.back());
            for (int j = 0; j + len < size; j++) {
                st[i][j] = std::min(st[i][j], st[i][j + len]);
            }
            len <<= 1;
        }
        log2.resize(size + 1, 0);
        for (int i = 2; i <= size; i++) {
            log2[i] = log2[i >> 1] + 1;
        }
    }

    int getMin(int qLeft, int qRight) {
        int level = log2[qRight - qLeft + 1];
        return std::min(st[level][qLeft], st[level][qRight - (1 << level) + 1]);
    }
};

struct Gap {

    int in;

    int out;

    static Gap read() {
        int in, out;
        scanf("%d %d", &in, &out);
        return {in, out};
    }
};

bool isCorrectTest(const int RANGE) {
    int nGuards;
    scanf("%d", &nGuards);
    std::vector<Gap> guards(nGuards);
    std::vector<int> base(RANGE + 1, 0);
    for (int i = 0; i < nGuards; i++) {
        guards[i] = Gap::read();
        base[guards[i].in]++;
        base[guards[i].out]--;
    }
    int curCount = 0;
    std::vector<int> countGuardsOnTimeline(RANGE + 1, 0);
    for (int i = 0; i <= RANGE; i++) {
        countGuardsOnTimeline[i] = curCount;
        curCount += base[i];
    }
    SparseTable st(RANGE + 1, countGuardsOnTimeline);
    if (st.getMin(1, RANGE) != 1) {
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
    const int MAX_TIMELINE = 10000;
    int nTests;
    scanf("%d", &nTests);
    for (int i = 0; i < nTests; i++) {
        if (isCorrectTest(MAX_TIMELINE)) {
            printf("Accepted");
        } else {
            printf("Wrong Answer");
        }
        printf("\n");
    }
    return 0;
}