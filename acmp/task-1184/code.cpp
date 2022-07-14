#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

// Time complexity: O((n + q) * log(n))
// Space complexity: O(n)

struct Cell {

    int val;

    int id;

    bool operator <(const Cell &a) const {
        if (val == a.val) {
            return id > a.id;
        }
        return val < a.val;
    }
};

class SegmentTree {

private:

    int size;

    std::vector<Cell> tree;

    void buildTree(int v, int left, int right, const std::vector<Cell> &a) {
        if (left == right) {
            tree[v] = a[left];
            return;
        }
        int mid = (left + right) / 2;
        buildTree(2 * v, left, mid, a);
        buildTree(2 * v + 1, mid + 1, right, a);
        tree[v] = std::max(tree[2 * v], tree[2 * v + 1]);
    }

    Cell maxTree(int v, int left, int right, int qLeft, int qRight) {
        if (qLeft <= left && right <= qRight) {
            return tree[v];
        }
        if (qRight < left || right < qLeft) {
            return {INT_MIN, INT_MIN};
        }
        int mid = (left + right) / 2;
        return std::max(maxTree(2 * v, left, mid, qLeft, qRight),
            maxTree(2 * v + 1, mid + 1, right, qLeft, qRight));
    }

public:

    SegmentTree(const std::vector<Cell> &a)
        : size((int) a.size())
    {
        tree.resize(4 * size);
        buildTree(1, 0, size - 1, a);
    }

    Cell getMaxOnRange(int qLeft, int qRight) {
        return maxTree(1, 0, size - 1, qLeft, qRight);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Cell> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].val);
        a[i].id = i;
    }
    SegmentTree tree(a);
    int nQueries;
    scanf("%d", &nQueries);
    for (int qI = 0; qI < nQueries; qI++) {
        int left, right;
        scanf("%d %d", &left, &right);
        Cell cur = tree.getMaxOnRange(left - 1, right - 1);
        printf("%d %d\n", cur.val, cur.id + 1);
    }
    return 0;
}