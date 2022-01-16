#include <stdio.h>

// Time complexity: O(range)
// Space complexity: O(1)

int main() {
    const int MAX_NUMBER = 1000000001;
    int left = 0;
    int right = MAX_NUMBER;
    char buf = ' ';
    while (buf != '=') {
        int mid = (left + right) / 2;
        printf("%d\n", mid);
        fflush(stdout);
        scanf(" %c", &buf);
        if (buf == '>') {
            left = mid;
        } else {
            right = mid;
        }
    }
    return 0;
}