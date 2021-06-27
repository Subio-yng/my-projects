#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int prev;
    scanf("%d", &prev);
    if (prev == 0) {
        printf("0");
        return 0;
    }
    int cur;
    scanf("%d", &cur);
    if (cur == 0) {
        printf("0");
        return 0;
    }
    int next = -1;
    int localMaxCount = 0;
    do {
        if (next != -1) {
            prev = cur;
            cur = next;
        }
        scanf("%d", &next);
        if (next != 0 && prev < cur && cur > next) {
            localMaxCount++;
        }
    } while (next != 0);
    printf("%d", localMaxCount);
    return 0;
}