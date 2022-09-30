#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

class FenwickTree {

private:

    int size;

    std::vector<long long> tree;

public:

    FenwickTree(int size)
            : size(size)
    {
        tree.resize(size, 0);
    }

    long long getSuffixSum(int qPos) {
        long long sum = 0;
        while (qPos < size) {
            sum += tree[qPos];
            qPos |= qPos + 1;
        }
        return sum;
    }

    void addValue(int qPos, int qVal) {
        while (qPos >= 0) {
            tree[qPos] += qVal;
            qPos = (qPos & qPos + 1) - 1;
        }
    }
};

struct Cell {

    int val;

    int id;

    bool operator <(const Cell &a) const {
        if (val == a.val) {
            return id < a.id;
        }
        return val < a.val;
    }
};

struct MergeCell {

    int val;

    int id1;

    int id2;
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Cell> list1(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list1[i].val);
        list1[i].id = i;
    }
    std::sort(list1.begin(), list1.end());
    std::vector<Cell> list2(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list2[i].val);
        list2[i].id = i;
    }
    std::sort(list2.begin(), list2.end());
    std::vector<MergeCell> list3(n);
    for (int i = 0; i < n; i++) {
        if (list1[i].val != list2[i].val) {
            printf("-1");
            return 0;
        }
        list3[i] = {list1[i].val, list1[i].id, list2[i].id};
    }
    std::sort(list3.begin(), list3.end(), [](const MergeCell &left, const MergeCell &right) {
        return left.id2 < right.id2;
    });
    long long sum = 0;
    FenwickTree tree(n);
    for (MergeCell mergeCell : list3) {
        sum += mergeCell.id1 + tree.getSuffixSum(mergeCell.id1 + 1) - mergeCell.id2;
        tree.addValue(mergeCell.id1, 1);
    }
    printf("%lld", sum);
    return 0;
}