#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nQ * log^3(size))
// Space complexity: O(size^3)

class FenwickTree {

private:

    int size;

    std::vector<std::vector<std::vector<long long>>> tree;

    long long getSumTree(int posZ, int posI, int posJ) {
        long long sum = 0;
        for (int z = posZ; z > 0; z = (z & z + 1) - 1) {
            for (int i = posI; i > 0; i = (i & i + 1) - 1) {
                for (int j = posJ; j > 0; j = (j & j + 1) - 1) {
                    sum += tree[z][i][j];
                }
            }
        }
        return sum;
    }

public:

    FenwickTree(int size)
        : size(size)
    {
        tree.resize(size + 1, std::vector(size + 1, std::vector(size + 1, 0LL)));
    }

    void addValue(int qZ, int qI, int qJ, int qVal) {
        for (int z = qZ; z <= size; z |= z + 1) {
            for (int i = qI; i <= size; i |= i + 1) {
                for (int j = qJ; j <= size; j |= j + 1) {
                    tree[z][i][j] = std::max(0LL, tree[z][i][j] + qVal);
                }
            }
        }
    }

    long long getSumOnRange(int qLeftZ, int qLeftI, int qLeftJ,
                            int qRightZ, int qRightI, int qRightJ
    ) {
        return getSumTree(qRightZ, qRightI, qRightJ) -
               getSumTree(qRightZ, qLeftI - 1, qRightJ) -
               getSumTree(qRightZ, qRightI, qLeftJ - 1) +
               getSumTree(qRightZ, qLeftI - 1, qLeftJ - 1) -
               getSumTree(qLeftZ - 1, qRightI, qRightJ) +
               getSumTree(qLeftZ - 1, qLeftI - 1, qRightJ) +
               getSumTree(qLeftZ - 1, qRightI, qLeftJ - 1) -
               getSumTree(qLeftZ - 1, qLeftI - 1, qLeftJ - 1);
    }
};

int main() {
    int size;
    scanf("%d", &size);
    FenwickTree cube(size);
    while (true) {
        char type;
        scanf(" %c", &type);
        if (type == '1') {
            int qI, qJ, qZ, qVal;
            scanf("%d %d %d %d", &qI, &qJ, &qZ, &qVal);
            cube.addValue(qZ + 1, qI + 1, qJ + 1, qVal);
        } else if (type == '2') {
            int qLeftI, qLeftJ, qLeftZ;
            scanf("%d %d %d", &qLeftI, &qLeftJ, &qLeftZ);
            int qRightI, qRightJ, qRightZ;
            scanf("%d %d %d", &qRightI, &qRightJ, &qRightZ);
            printf("%lld\n", cube.getSumOnRange(qLeftZ + 1, qLeftI + 1, qLeftJ + 1,
                                                qRightZ + 1, qRightI + 1, qRightJ + 1));
        } else {
            break;
        }
    }
    return 0;
}