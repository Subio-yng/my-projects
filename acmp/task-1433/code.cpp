#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

// Time complexity: O(n * log(n) + q)
// Space complexity: O(n * log(n))

const int DIV = 1 << 16;

short getR15(int &curR31) {
    curR31 = (1LL * curR31 * 1103515245 + 12345) & INT_MAX;
    return short(curR31 / DIV);
}

int main() {
    int n, q, curR31;
    scanf("%d %d %d", &n, &q, &curR31);
    std::vector<std::vector<short>> st(1, std::vector<short>(n));
    for (int i = 0; i < n; i++) {
        st[0][i] = getR15(curR31);
    }
    int len = 1;
    for (int i = 1; len * 2 <= n; i++) {
        st.push_back(st.back());
        for (int j = 0; j + len < n; j++) {
            st[i][j] = std::min(st[i][j], st[i][j + len]);
        }
        len *= 2;
    }
    std::vector<short> log2(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        log2[i] = log2[i >> 1] + 1;
    }
    int sum = 0;
    for (int i = 0; i < q; i++) {
        short left = getR15(curR31) & (n - 1);
        short right = getR15(curR31) & (n - 1);
        if (left > right) {
            std::swap(left, right);
        }
        int len = right - left + 1;
        short level = log2[len];
        sum = (sum + std::min(st[level][left], st[level][right - (1 << level) + 1])) & INT_MAX;
    }
    printf("%d", sum);
    return 0;
}