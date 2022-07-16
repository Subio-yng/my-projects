#include <stdio.h>
#include <vector>

// Time complexity: O((n + q) * log(n))
// Space complexity: O(n)

class SegmentTree {

private:

    int size;

    std::vector<long long> tree;

    void buildTree(int v, int left, int right, const std::vector<int> &a) {
        if (left == right) {
            tree[v] = a[left];
            return;
        }
        int mid = (left + right) / 2;
        buildTree(2 * v, left, mid, a);
        buildTree(2 * v + 1, mid + 1, right, a);
        tree[v] = 0;
    }

    long long valueTree(int v, int left, int right, int qPos) {
        if (qPos < left || right < qPos) {
            return 0;
        }
        if (left == qPos && qPos == right) {
            return tree[v];
        }
        int mid = (left + right) / 2;
        return tree[v] + 
            valueTree(2 * v, left, mid, qPos) +
            valueTree(2 * v + 1, mid + 1, right, qPos);
    }

    void updateTree(int v, int left, int right, int qLeft, int qRight, int qVal) {
        if (qRight < left || right < qLeft) {
            return;
        }
        if (qLeft <= left && right <= qRight) {
            tree[v] += qVal;
            return;
        }
        int mid = (left + right) / 2;
        updateTree(2 * v, left, mid, qLeft, qRight, qVal);
        updateTree(2 * v + 1, mid + 1, right, qLeft, qRight, qVal);
    }

public:

    SegmentTree(const std::vector<int> &a)
        : size((int) a.size())
    {
        tree.resize(4 * size);
        buildTree(1, 0, size - 1, a);
    }

    long long getValueByPos(int qPos) {
        return valueTree(1, 0, size - 1, qPos);
    }

    void addOnRange(int qLeft, int qRight, int qVal) {
        updateTree(1, 0, size - 1, qLeft, qRight, qVal);
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
        if (type == 'g') {
            int pos;
            scanf("%d", &pos);
            printf("%lld ", tree.getValueByPos(pos - 1));
        } else if (type == 'a') {
            int left, right, val;
            scanf("%d %d %d", &left, &right, &val);
            tree.addOnRange(left - 1, right - 1, val);
        } else {
            throw 1;
        }
    }
    return 0;
}