#include <stdio.h>

// Time complexity: O(length)
// Space complexity: O(1)

int main() {
    int length;
    scanf("%d", &length);
    int capital, lowercase, number;
    scanf("%d %d %d", &capital, &lowercase, &number);
    for (int i = 0; i < length; i++) {
        if (capital > 0) {
            printf("%c", 'A' + i % 26);
            capital--;
        } else if (lowercase > 0) {
            printf("%c", 'a' + i % 26);
            lowercase--;
        } else if (number > 0) {
            printf("%c", '0' + i % 10);
            number--;
        } else {
            printf("%c", 'A' + i % 26);
        }
    }
    return 0;
}