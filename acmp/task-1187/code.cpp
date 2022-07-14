#include <stdio.h>
#include <vector>

// Time complexity: O((n + q) * log(n))
// Space complexity: O(n)

int getGcd(int a, int b) {
    while (b > 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

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
        tree[v] = getGcd(tree[2 * v], tree[2 * v + 1]);
    }

    int gcdTree(int v, int left, int right, int qLeft, int qRight) {
        if (qLeft <= left && right <= qRight) {
            return tree[v];
        }
        if (qRight < left || right < qLeft) {
            return 0;
        }
        int mid = (left + right) / 2;
        return getGcd(gcdTree(2 * v, left, mid, qLeft, qRight),
            gcdTree(2 * v + 1, mid + 1, right, qLeft, qRight));
    }

    void updateTree(int v, int left, int right, int qPos, int qVal) {
        if (qPos < left || right < qPos) {
            return;
        }
        if (left == right) {
            tree[v] = qVal;
            return;
        }
        int mid = (left + right) / 2;
        updateTree(2 * v, left, mid, qPos, qVal);
        updateTree(2 * v + 1, mid + 1, right, qPos, qVal);
        tree[v] = getGcd(tree[2 * v], tree[2 * v + 1]);
    }

public:

    SegmentTree(const std::vector<int> &a)
        : size((int) a.size())
    {
        tree.resize(4 * size);
        buildTree(1, 0, size - 1, a);
    }

    int getGcdOnRange(int qLeft, int qRight) {
        return gcdTree(1, 0, size - 1, qLeft, qRight);
    }

    void updateValue(int qPos, int qVal) {
        updateTree(1, 0, size - 1, qPos, qVal);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    SegmentTree tree(a);
    int nQueries;
    scanf("%d", &nQueries);
    for (int qI = 0; qI < nQueries; qI++) {
        char type;
        scanf(" %c", &type);
        if (type == 'u') {
            int pos, val;
            scanf("%d %d", &pos, &val);
            tree.updateValue(pos - 1, val);
        } else if (type == 'g') {
            int left, right;
            scanf("%d %d", &left, &right);
            printf("%d ", tree.getGcdOnRange(left - 1, right - 1));
        } else {
            throw 1;
        }
    }
    return 0;
}