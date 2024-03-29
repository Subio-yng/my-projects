#include <stdio.h>
#include <vector>
#include <string>
 
// Time complexity: O(n + nQ * log(n))
// Space complexity: O(n)
 
class FenwickTree {
 
private:
     
    int size;
     
    std::vector<long long> tree;
     
    long long getPrefSum(int pos) {
        long long sum = 0;
        while (pos > 0) {
            sum += tree[pos];
            pos = (pos & (pos + 1)) - 1;
        }
        return sum;
    }
     
public:
 
    FenwickTree(int size)
        : size(size)
    {
        tree.resize(size + 1, 0);
    }
 
    long long getSumOnRange(int qLeft, int qRight) {
        return getPrefSum(qRight) - getPrefSum(qLeft - 1);
    }
     
    void updateValue(int qPos, int qVal) {
        while (qPos <= size) {
            tree[qPos] += qVal;
            qPos |= qPos + 1;
        }
    }
};
 
int main() {
    int n, nQ;
    scanf("%d %d", &n, &nQ);
    FenwickTree tree(n);
    for (int i = 0; i < nQ; i++) {
        char buf[1 + 3];
        scanf(" %s", &buf);
        if (std::string(buf) == "add") {
            int qPos, qVal;
            scanf("%d %d", &qPos, &qVal);
            tree.updateValue(qPos, qVal);
        } else {
            int qLeft, qRight;
            scanf("%d %d", &qLeft, &qRight);
            printf("%lld\n", tree.getSumOnRange(qLeft, qRight));
        }
    }
    return 0;
}