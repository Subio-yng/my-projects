#include <stdio.h>

// Time complexity: O(n)
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
    int prevLocalMaxIndex = -1;
    int curLocalMaxIndex = -1;
    int minDistance = 0;
    int i = 0;
    do {
        if (next != -1) {
            prev = cur;
            cur = next;
        }
        scanf("%d", &next);
        if (next != 0 && prev < ñur && cur > next) {
            prevLocalMaxIndex = curLocalMaxIndex;
            curLocalMaxIndex = i;
            if (prevLocalMaxIndex != -1 && 
                (minDistance == 0 || curLocalMaxIndex - prevLocalMaxIndex < minDistance)
            ) {
                minDistance = curLocalMaxIndex - prevLocalMaxIndex;
            }
        }
        i++;
    } while (next != 0);
    printf("%d", minDistance);
    return 0;
}