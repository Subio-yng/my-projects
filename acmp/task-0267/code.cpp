#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int n, t1, t2;
    scanf("%d %d %d", &n, &t1, &t2);
    int time = std::min(t1, t2);
    n--;
    if (n == 0) {
        printf("%d", time);
        return 0;
    }
    int left = 0;
    int right = 1000000000;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (mid / t1 + mid / t2 < n) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%d", time + right);
    return 0;
}