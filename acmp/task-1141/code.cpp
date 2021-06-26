#include <stdio.h>

// Time comeplexity: O(n)
// Space complexity: O(1)

int main() {
    int n;
    int prev;
    scanf("%d", &n);
    int maxSequence = 1, temp = 1;
    do {
        prev = n;
        scanf("%d", &n);
        if (n == prev) {
            temp++;
        } else {
            if (temp > maxSequence) {
                maxSequence = temp;
            }
            temp = 1;
        }
    } while (n != 0);
    printf("%d", maxSequence);
    return 0;
}