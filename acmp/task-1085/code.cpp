#include <stdio.h>
#include <vector>
#include <string>

// Time complexity: O(size^2 + nQ * log(size))
// Space complexity: O(size^2)

class FenwickTree {

private:

    int size;

    std::vector<std::vector<int>> tree;

    int getSumTree(int posI, int posJ) {
        int sum = 0;
        for (int i = posI; i > 0; i = (i & i + 1) - 1) {
            for (int j = posJ; j > 0; j = (j & j + 1) - 1) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

public:

    FenwickTree(int size)
        : size(size)
    {
        tree.resize(size + 1, std::vector<int>(size + 1, 0));
    }

    void addValue(int qI, int qJ) {
        for (int i = qI; i <= size; i |= i + 1) {
            for (int j = qJ; j <= size; j |= j + 1) {
                tree[i][j]++;
            }
        }
    }

    int getSumOnRange(int qLeftI, int qLeftJ, int qRightI, int qRightJ) {
        return getSumTree(qRightI, qRightJ) -
               getSumTree(qLeftI - 1, qRightJ) -
               getSumTree(qRightI, qLeftJ - 1) +
               getSumTree(qLeftI - 1, qLeftJ - 1);
    }
};

int main() {
    int size, nQ;
    scanf("%d %d", &size, &nQ);
    FenwickTree table(size);
    for (int i = 0; i < nQ; i++) {
        char buf[1 + 3];
        scanf(" %s", &buf);
        if (std::string(buf) == "add") {
            int qI, qJ;
            scanf("%d %d", &qI, &qJ);
            table.addValue(qI, qJ);
        } else {
            int qLeftI, qLeftJ, qRightI, qRightJ;
            scanf("%d %d %d %d", &qLeftI, &qLeftJ, &qRightI, &qRightJ);
            printf("%d\n", table.getSumOnRange(qLeftI, qLeftJ, qRightI, qRightJ));
        }
    }
    return 0;
}