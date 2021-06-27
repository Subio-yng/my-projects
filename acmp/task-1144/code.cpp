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
    int posI = 0, posJ = -1, i = 0;
    int minDistance = 0;
    do {
        if (next != -1) {
            prev = cur;
            cur = next;
        }
        scanf("%d", &next);
        if (next != 0 && cur > prev && cur > next) {
            posI = posJ;
            posJ = i;
            if (posI != -1 && (minDistance == 0 || posJ - posI < minDistance)) {
                minDistance = posJ - posI;
            }
        }
        i++;
    } while (next != 0);
    printf("%d", minDistance);
    return 0;
}