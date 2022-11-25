#include <bits/stdc++.h>

// Time complexity: O(n + nQ)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> numbs(n);
    long long curSum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbs[i]);
        curSum += numbs[i];
    }
    int curShift = 0;
    int nQ;
    scanf("%d", &nQ);
    for (int i = 0; i < nQ; i++) {
        char type;
        scanf(" %c", &type);
        if (type == '1') {
            int pos, val;
            scanf("%d %d", &pos, &val);
            pos = (n + pos - 1 - curShift) % n;
            curSum += val - numbs[pos];
            numbs[pos] = val;
        } else {
            int val;
            scanf("%d", &val);
            curShift = (curShift + val) % n;
        }
        printf("%lld\n", curSum);
    }
    return 0;
}