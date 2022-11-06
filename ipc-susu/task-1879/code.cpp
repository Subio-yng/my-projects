#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    while (!(n < k)) {
        if (n > 100) {
            k += 5;
        } else {
            k++;
        }
        if (k < 20) {
            n -= 11;
        }
        n -= 3;
    }
    printf("%d", n + k);
    return 0;
}