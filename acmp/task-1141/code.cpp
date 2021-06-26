#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int cur;
    int prev;
    scanf("%d", &cur);
    int maxSequence = 1, temp = 1;
    do {
        prev = cur;
        scanf("%d", &cur);
        if (cur == prev) {
            temp++;
        } else {
            if (temp > maxSequence) {
                maxSequence = temp;
            }
            temp = 1;
        }
    } while (cur != 0);
    printf("%d", maxSequence);
    return 0;
}