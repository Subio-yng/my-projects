#include <stdio.h>
#include <vector>

// Time complexity: O((n + q) * log(n))
// Space complexity: O(n)

class Tree {

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
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

    long long sumTree(int v, int left, int right, int qLeft, int qRight) {
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

    void updateTree(int v, int left, int right, int i, int val) {
        if (i < left || right < i) {
            return;
        }
        if (left == right) {
            tree[v] = val;
            return;
        }
        int mid = (left + right) / 2;
        updateTree(2 * v, left, mid, i, val);
        updateTree(2 * v + 1, mid + 1, right, i, val);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

public:

    Tree(const std::vector<int> &a)
        : size((int) a.size())
    {
        tree.resize(4 * size);
        buildTree(1, 0, size - 1, a);
    }

    long long getSumOnRange(int qLeft, int qRight) {
        return sumTree(1, 0, size - 1, qLeft, qRight);
    }

    void update(int i, int val) {
        updateTree(1, 0, size - 1, i, val);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    Tree tree(a);
    int q;
    scanf("%d", &q);
    for (int qI = 0; qI < q; qI++) {
        char type;
        scanf(" %c", &type);
        if (type == 'u') {
            int i, val;
            scanf("%d %d", &i, &val);
            tree.update(i - 1, val);
        } else if (type == 's') {
            int left, right;
            scanf("%d %d", &left, &right);
            printf("%lld ", tree.getSumOnRange(left - 1, right - 1));
        } else {
            throw 1;
        }
    }
}