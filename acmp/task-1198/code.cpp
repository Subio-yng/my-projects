#include <stdio.h>

// Time complexity: O(length)
// Space complexity: O(1)

int main() {
    const int MODLETTERS = 26;
    const int MODNUMBERS = 10;
    int length;
    scanf("%d", &length);
    int uppercase, lowercase, number;
    scanf("%d %d %d", &uppercase, &lowercase, &number);
    for (int i = 0; i < length; i++) {
        if (uppercase > 0) {
            printf("%c", 'A' + i % MODLETTERS);
            uppercase--;
        } else if (lowercase > 0) {
            printf("%c", 'a' + i % MODLETTERS);
            lowercase--;
        } else if (number > 0) {
            printf("%c", '0' + i % MODNUMBERS);
            number--;
        } else {
            printf("%c", 'A' + i % MODLETTERS);
        }
    }
    return 0;
}