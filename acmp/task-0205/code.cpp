#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int hours, minutes, seconds;
    scanf("%d:%d:%d", &hours, &minutes, &seconds);
    int val1;
    scanf("%d", &val1);
    char next;
    int code = scanf("%c", &next);
    int days = 0;
    if (code != EOF && next != '\n') {
        int val2;
        scanf("%d", &val2);
        code = scanf("%c", &next);
        if (code != EOF && next != '\n') {
            int val3;
            scanf("%d", &val3);
            seconds += val3 % 60;
            minutes += seconds / 60 + val2 % 60 + val3 / 60 % 60;
            hours += minutes / 60 + val1 % 24 + val2 / 60 % 24 + val3 / 3600 % 24;
            days += val1 / 24 + val2 / 1440 + val3 / 86400;
        } else {
            seconds += val2 % 60;
            minutes += seconds / 60 + val1 % 60 + val2 / 60 % 60;
            hours += minutes / 60 + val1 / 60 % 24 + val2 / 3600 % 24;
            days += val1 / 1440 + val2 / 86400;
        }
    } else {
        seconds += val1 % 60;
        minutes += seconds / 60 + val1 / 60 % 60;
        hours += minutes / 60 + val1 / 3600 % 24;
        days += val1 / 86400;
    }
    days += hours / 24;
    hours %= 24;
    minutes %= 60;
    seconds %= 60;
    if (hours < 10) {
        printf("0");
    }
    printf("%d:", hours);
    if (minutes < 10) {
        printf("0");
    }
    printf("%d:", minutes);
    if (seconds < 10) {
        printf("0");
    }
    printf("%d", seconds);
    if (days > 0) {
        printf("+%d days", days);
    }
    return 0;
}