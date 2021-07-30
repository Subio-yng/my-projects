#include <stdio.h>

// Time complexity: O(n + k)
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    int cnt[201];
    for (int i = 0; i < 201; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        cnt[val + 100]++;
    }
    for (int i = 0; i < 201; i++) {
        for (int k = 0; k < cnt[i]; k++) {
            printf("%d ", i - 100);
        }
    }
    return 0;
}