#include <stdio.h>
#include <vector>

// Time complexity: O((n + q) * log(n))
// Space complexity: O(n)

class SegmentTree {

private:

    int size;

    std::vector<long long> tree;

    void boostTree(int v, int left, int right, long long &boost, int qPos) {
        if (qPos < left || right < qPos) {
            return;
        }
        boost += tree[v];
        if (left != right) {
            int mid = (left + right) / 2;
            boostTree(2 * v, left, mid, boost, qPos);
            boostTree(2 * v + 1, mid + 1, right, boost, qPos);
        }
    }

    void updateTree(int v, int left, int right, int qLeft, int qRight, int qVal) {
        if (qRight < left || right < qLeft) {
            return;
        }
        if (qLeft <= left && right <= qRight) {
            tree[v] += qVal;
        } else {
            int mid = (left + right) / 2;
            updateTree(2 * v, left, mid, qLeft, qRight, qVal);
            updateTree(2 * v + 1, mid + 1, right, qLeft, qRight, qVal);
        }
    }

public:

    SegmentTree(int size)
        : size(size)
    {
        tree.resize(4 * size, 0);
    }

    long long getBoostOnRange(int qPos) {
        long long sumBoost = 0;
        boostTree(1, 0, size - 1, sumBoost, qPos);
        return sumBoost;
    }

    void updateRange(int qLeft, int qRight, int qVal) {
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
    SegmentTree tree(n);
    int nQueries;
    scanf("%d", &nQueries);
    for (int qI = 0; qI < nQueries; qI++) {
        char type;
        scanf(" %c", &type);
        if (type == 'g') {
            int pos;
            scanf("%d", &pos);
            printf("%lld ", tree.getBoostOnRange(pos - 1) + a[pos - 1]);
        } else if (type == 'a') {
            int left, right, val;
            scanf("%d %d %d", &left, &right, &val);
            tree.updateRange(left - 1, right - 1, val);
        } else {
            throw 1;
        }
    }
    return 0;
}