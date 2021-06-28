#include <stdio.h>
#include <algorithm>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    int cur;
    scanf("%d", &cur);
    if (cur == 0) {
        printf("0");
        return 0;
    }
    int prev;
    int maxLen = 1;
    int countLess = 1;
    int countGreater = 1;
    do {
        prev = cur;
        scanf("%d", &cur);
        if (cur != 0) {
            if (prev < cur) {
                countGreater++;
            } else {
                countGreater = 1;
            }
            if (prev > cur) {
                countLess++;
            } else {
                countLess = 1;
            }
            maxLen = std::max(maxLen, countLess);
            maxLen = std::max(maxLen, countGreater);
        }
    } while (cur != 0);
    printf("%d", maxLen);
    return 0;
}