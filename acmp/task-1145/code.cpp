#include <stdio.h>
#include <cmath>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    int n;
    double s = 0;
    int length = -1;
    int sum = 0;
    do {
        length++;
        scanf("%d", &n);
        s += n;
        sum += n * n;
    } while (n != 0);
    double avg = s / length;
    double ans = sqrt((sum - 2 * s * avg + length * std::pow(avg, 2)) / (length - 1));
    printf("%.3f", ans);
    return 0;
}