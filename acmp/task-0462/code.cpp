#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", (n + 1) / 2 - (n + 3) / 6 - (n + 5) / 10 + (n + 15) / 30);
    return 0;
}