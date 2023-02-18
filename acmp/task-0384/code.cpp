#include <bits/stdc++.h>

// Time complexity: O(log(min(i, j)))
// Space complexity: O(1)

int getGcd(int a, int b) {
    while (b > 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);
    i = getGcd(i, j);
    const int MOD = 1'000'000'000;
    int prevFib = 0;
    int curFib = 1;
    while (i > 1) {
        int tmp = curFib;
        curFib += prevFib;
        if (curFib >= MOD) {
            curFib -= MOD;
        }
        prevFib = tmp;
        i--;
    }
    printf("%d", curFib);
    return 0;
}