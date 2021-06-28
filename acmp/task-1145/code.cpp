#include <stdio.h>
#include <cmath>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    int n;
    int length = -1;
    int sumSquares = 0, sum = 0;
    do {
        length++;
        scanf("%d", &n);
        sum += n;
        sumSquares += n * n;
    } while (n != 0);
    double avg = sum / length;
    double ans = sqrt((sumSquares - 2 * sum * avg + length * std::pow(avg, 2)) / (length - 1));
    printf("%.3f", ans);
    return 0;
}