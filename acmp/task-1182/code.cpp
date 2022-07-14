#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O((n + q) * log(n))
// Space complexity: O(n)

class SegmentTree {

private:

    int size;

    std::vector<int> tree;

    int maxTree(int v, int left, int right, int qLeft, int qRight) {
        if (qLeft <= left && right <= qRight) {
            return tree[v];
        }
        if (qRight < left || right < qLeft) {
            return 0;
        }
        int mid = (left + right) / 2;
        return std::max(maxTree(2 * v, left, mid, qLeft, qRight),
            maxTree(2 * v + 1, mid + 1, right, qLeft, qRight));
    }

    void updateTree(int v, int left, int right, int qLeft, int qRight) {
        if (qRight < left || right < qLeft) {
            return;
        }
        if (left == right) {
            tree[v]++;
            return;
        }
        int mid = (left + right) / 2;
        updateTree(2 * v, left, mid, qLeft, qRight);
        updateTree(2 * v + 1, mid + 1, right, qLeft, qRight);
        tree[v] = std::max(tree[2 * v], tree[2 * v + 1]);
    }

public:

    SegmentTree(int size)
        : size(size)
    {
        tree.resize(4 * size, 0);
    }

    int getMaxOnRange(int qLeft, int qRight) {
        return maxTree(1, 0, size - 1, qLeft, qRight);
    }

    void updateRange(int qLeft, int qRight) {
        updateTree(1, 0, size - 1, qLeft, qRight);
    }
};

int main() {
    int n, nSpace, nQueries;
    scanf("%d %d %d", &n, &nSpace, &nQueries);
    SegmentTree train(n);
    for (int qI = 0; qI < nQueries; qI++) {
        int left, right;
        scanf("%d %d", &left, &right);
        right--;
        if (train.getMaxOnRange(left, right) < nSpace) {
            printf("Yes\n");
            train.updateRange(left, right);
        } else {
            printf("No\n");
        }
    }
    return 0;
}