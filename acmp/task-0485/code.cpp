#include <bits/stdc++.h>

// Space complexity: O(1)

bool isAns(int x, int n, int cur, int residue) {
    if (cur > 0 && x % n == residue) {
        return isAns(x - x / n - residue, n, cur - 1, residue);
    }
    return cur == 0;
}

int main() {
    int n, residue;
    scanf("%d %d", &n, &residue);
    int x = n * (residue + 1);
    while (!isAns(x, n, n, residue)) {
        x++;
    }
    printf("%d", x);
    return 0;
}
