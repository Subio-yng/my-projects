#include <stdio.h>

// Time complexity: O(n + k)
// Space complexity: O(1)

int main() {
    const int MAX_TEMPERATURE = 200;
    int n;
    scanf("%d", &n);
    int cnt[MAX_TEMPERATURE + 1];
    for (int i = 0; i <= MAX_TEMPERATURE; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        cnt[val + 100]++;
    }
    for (int iNum = 0; iNum <= MAX_TEMPERATURE; iNum++) {
        for (int iCount = 0; iCount < cnt[iNum]; iCount++) {
            printf("%d ", iNum - 100);
        }
    }
    return 0;
}