#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int hours, minutes, seconds;
    scanf("%d:%d:%d", &hours, &minutes, &seconds);
    int val1, val2 = -1, val3 = -1;
    int days = 0;
    scanf("%d:%d:%d", &val1, &val2, &val3);
    if (val2 == -1) {
        val2 = 0;
        val3 = 0;
    } else if (val3 == -1) {
        std::swap(val1, val2);
        val3 = 0;
    } else {
        std::swap(val1, val3);
    }
    seconds += val1 % 60;
    minutes += seconds / 60 + val1 / 60 % 60 + val2 % 60;
    hours += minutes / 60 + val1 / 3600 % 24 + val2 / 60 % 24 + val3 % 24;
    days += hours / 24 + val1 / 86400 + val2 / 1440 + val3 / 24;
    printf("%02d:%02d:%02d", hours % 24, minutes % 60, seconds % 60);
    if (days > 0) {
        printf("+%d days", days);
    }
    return 0;
}