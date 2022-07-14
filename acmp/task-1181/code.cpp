#include <stdio.h>
#include <vector>

// Time complexity: O((n + q) * log(n))
// Space complexity: O(n)

class SegmentTree {

private:

    int size;

    std::vector<int> tree;

    void buildTree(int v, int left, int right, const std::vector<bool> &a) {
        if (left == right) {
            if (a[left]) {
                tree[v] = 1;
            } else {
                tree[v] = 0;
            }
            return;
        }
        int mid = (left + right) / 2;
        buildTree(2 * v, left, mid, a);
        buildTree(2 * v + 1, mid + 1, right, a);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

    int sumTree(int v, int left, int right, int qLeft, int qRight) {
        if (qLeft <= left && right <= qRight) {
            return tree[v];
        }
        if (qRight < left || right < qLeft) {
            return 0;
        }
        int mid = (left + right) / 2;
        return sumTree(2 * v, left, mid, qLeft, qRight) +
            sumTree(2 * v + 1, mid + 1, right, qLeft, qRight);
    }

public:

    SegmentTree(const std::vector<bool> &a)
        : size((int) a.size())
    {
        tree.resize(4 * size);
        buildTree(1, 0, size - 1, a);
    }

    int getSumOnRange(int qLeft, int qRight) {
        return sumTree(1, 0, size - 1, qLeft, qRight);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<bool> a(n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        a[i] = val == 0;
    }
    SegmentTree tree(a);
    int nQueries;
    scanf("%d", &nQueries);
    for (int qI = 0; qI < nQueries; qI++) {
        int left, right;
        scanf("%d %d", &left, &right);
        printf("%d ", tree.getSumOnRange(left - 1, right - 1));
    }
    return 0;
}