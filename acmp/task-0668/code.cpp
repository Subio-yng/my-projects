#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int head, tail;
    scanf("%d %d", &head, &tail);
    if (head % 2 != 0 && tail == 0) {
        printf("-1");
        return 0;
    }
    int count = 0;
    if ((head + tail / 2) % 2 != 0) {
        tail++;
        count++;
        if (tail % 2 != 0) {
            tail++;
            count++;
        }
    }
    head += tail / 2;
    count += tail / 2 + head / 2;
    if (tail % 2 != 0) {
        count += 6;
    }
    printf("%d", count);
    return 0;
}