#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    const int LIMIT = 12;
    int n;
    scanf("%d", &n);
    int pair = n % LIMIT;
    int bunch = n / LIMIT % LIMIT;
    int box = n / (LIMIT * LIMIT);
    if (bunch == LIMIT - 1 && pair > 1) {
        bunch = 0;
        pair = 0;
        box++;
    }
    if (pair >= LIMIT - 2) {
        pair = 0;
        bunch++;
    }
    if (bunch >= LIMIT) {
        bunch = 0;
        box++;
    }
    printf("%d %d %d", box, bunch, pair);
    return 0;
}