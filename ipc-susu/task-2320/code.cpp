#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int s, p;
    scanf("%d %d", &s, &p);
    for (int i = 0; i <= 1000; i++) {
        for (int j = i; j <= 1000; j++) {
            if (i + j == s && i * j == p) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    return 0;
}