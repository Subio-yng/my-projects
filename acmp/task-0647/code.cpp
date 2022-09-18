#include <stdio.h>
#include <vector>

// Time complexity: O((n + nQ) * log(n))
// Space complexity: O(n + nQ)

class FenwickTree {

private:

    int size;

    std::vector<long long> tree;

public:

    FenwickTree(int size)
        : size(size)
    {
        tree.resize(size + 1, 0);
    }

    void addValue(int qPos, int qVal) {
        while (qPos <= size) {
            tree[qPos] += qVal;
            qPos |= qPos + 1;
        }
    }

    long long getPrefSum(int qPos) {
        long long sum = 0;
        while (qPos > 0) {
            sum += tree[qPos];
            qPos = (qPos & qPos + 1) - 1;
        }
        return sum;
    }
};

int main() {
    int n, nQ;
    scanf("%d %d", &n, &nQ);
    FenwickTree tree(n + nQ);
    std::vector<int> valPos(n + 2);
    for (int i = nQ; i <= n + nQ; i++) {
        tree.addValue(i, 1);
        valPos[i - nQ + 1] = i;
    }
    int front = nQ;
    for (int i = 0; i < nQ; i++) {
        int qVal;
        scanf("%d", &qVal);
        if (valPos[qVal] != front) {
            printf("%lld ", tree.getPrefSum(valPos[qVal]));
            tree.addValue(valPos[qVal], -1);
            front--;
            valPos[qVal] = front;
            tree.addValue(front, 1);
        } else {
            printf("1 ");
        }
    }
    return 0;
}