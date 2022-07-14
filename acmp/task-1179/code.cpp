#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

class SegmentTree {

private:

    int size;

    std::vector<int> tree;

    void buildTree(int v, int left, int right, const std::vector<int> &a) {
        if (left == right) {
            tree[v] = a[left];
            return;
        }
        int mid = (left + right) / 2;
        buildTree(2 * v, left, mid, a);
        buildTree(2 * v + 1, mid + 1, right, a);
        tree[v] = std::min(tree[2 * v], tree[2 * v + 1]);
    }

    int minTree(int v, int left, int right, int qLeft, int qRight) {
        if (qLeft <= left && right <= qRight) {
            return tree[v];
        }
        if (qRight < left || right < qLeft) {
            return INT_MAX;
        }
        int mid = (left + right) / 2;
        return std::min(minTree(2 * v, left, mid, qLeft, qRight),
            minTree(2 * v + 1, mid + 1, right, qLeft, qRight));
    }

public:

    SegmentTree(const std::vector<int> &a)
        : size((int) a.size())
    {
        tree.resize(4 * size);
        buildTree(1, 0, size - 1, a);
    }

    int getMinOnRange(int qLeft, int qRight) {
        return minTree(1, 0, size - 1, qLeft, qRight);
    }
};

int main() {
    int n, qLen;
    scanf("%d %d", &n, &qLen);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    SegmentTree tree(a);
    for (int left = 0; left <= n - qLen; left++) {
        printf("%d ", tree.getMinOnRange(left, left + qLen - 1));
    }
    return 0;
}