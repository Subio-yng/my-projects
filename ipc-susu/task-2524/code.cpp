#include <stdio.h>

// Time complexity: O(log(n))
// Space complexity: O(1)

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int s = 0;
    while (n > 0) {
        if (n % 2 != 0) {
            s += m + 1;
        }
        m *= 2;
        n /= 2;
    }
    printf("%d", s);
    return 0;
}