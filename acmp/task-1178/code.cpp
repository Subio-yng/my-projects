#include <stdio.h>
#include <vector>

// Time complexity: O(nQ * log(RANGE)^2)
// Space complexity: O(RANGE)

class FenwickTree {

private:

    int size;

    std::vector<long long> tree;

public:

    FenwickTree(int size)
        : size(size)
    {
        tree.resize(size, 0);
    }

    void addValue(int qPos, int qVal) {
        while (qPos >= 0) {
            tree[qPos] += qVal;
            qPos = (qPos & qPos + 1) - 1;
        }
    }

    long long getSufSum(int qPos) {
        long long sum = 0;
        while (qPos < size) {
            sum += tree[qPos];
            qPos |= qPos + 1;
        }
        return sum;
    }
};

int main() {
    const int RANGE = 100'000;
    FenwickTree order(RANGE);
    int nQ;
    scanf("%d", &nQ);
    for (int i = 0; i < nQ; i++) {
        char type;
        scanf(" %c", &type);
        if (type == '1') {
            int qPos;
            scanf("%d", &qPos);
            qPos--;
            printf("%lld\n", order.getSufSum(qPos));
            order.addValue(qPos, 1);
        } else {
            int qVal;
            scanf("%d", &qVal);
            int left = RANGE;
            int right = 0;
            while (right + 1 < left) {
                int mid = (left + right) / 2;
                if (order.getSufSum(mid) <= qVal) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            order.addValue(right, -1);
        }
    }
    return 0;
}