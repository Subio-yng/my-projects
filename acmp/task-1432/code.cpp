#include <stdio.h>
#include <vector>
#include <climits>
 
// Time complexity: O(n + q)
// Space complexity: O(n)
 
const int DIV = 1 << 16;
 
int getR15(int &curR31) {
    curR31 = (1LL * curR31 * 1103515245 + 12345) & INT_MAX;
    return curR31 / DIV;
}

int main() {
    int n, q, curR31;
    scanf("%d %d %d", &n, &q, &curR31);
    std::vector<int> prefSum(n + 1);
    prefSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefSum[i] = (prefSum[i - 1] + getR15(curR31)) & INT_MAX;
    }
    int sum = 0;
    for (int i = 0; i < q; i++) {
        int left = 1 + (getR15(curR31) & n - 1);
        int right = 1 + (getR15(curR31) & n - 1);
        if (left > right) {
            std::swap(left, right);
        }
        int curSum = prefSum[right] - prefSum[left - 1];
        if (curSum < 0) {
            curSum += INT_MAX;
        }
        sum = (sum + curSum) & INT_MAX;
    }
    printf("%d", sum);
    return 0;
}