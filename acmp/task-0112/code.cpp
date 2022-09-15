#include <stdio.h>
#include <vector>

// Time complexity: O(t * n * log(n))
// Space complexity: O(t * n)

class FenwickTree {

private:

    int size;

    std::vector<int> tree;

    int getSumTree(int pos) {
        int sum = 0;
        while (0 < pos) {
            sum += tree[pos];
            pos = (pos & pos + 1) - 1;
        }
        return sum;
    }

public:

    FenwickTree(int n)
        : size(n)
    {
        tree.resize(n + 1, 0);
    }

    void addValue(int qPos, int qVal) {
        while (qPos <= size) {
            tree[qPos] += qVal;
            qPos |= qPos + 1;
        }
    }

    int getSumOnRange(int qLeft, int qRight) {
        return getSumTree(qRight) - getSumTree(qLeft - 1);
    }
};

int solve(int n) {
    FenwickTree tree(n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        sum += tree.getSumOnRange(val, n);
        tree.addValue(val, 1);
    }
    return sum;
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    int sum = 0;
    while (t--) {
        sum += solve(n);
    }
    printf("%d", sum);
    return 0;
}