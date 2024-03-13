#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", n - (n / 2 + n / 3 - n / 6 + n / 5 - n / 10 - n / 15 + n / 30));
    return 0;
}