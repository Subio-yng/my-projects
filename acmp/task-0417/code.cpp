#include <stdio.h>

// Time complexity: O(n)
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    int curDay = 1, curMonth = 1;
    int curYear = 2008;
    int dayOfWeek = 1;
    for (int i = 0; i < n; i++) {
        int daysInFebruary;
        if (curYear % 4 == 0 && curYear % 100 != 0 || 
            curYear % 400 == 0
        ) {
            daysInFebruary = 29;
        } else {
            daysInFebruary = 28;
        }
        int daysInMonth;
        if (curMonth == 2) {
            daysInMonth = daysInFebruary;
        } else if (curMonth == 4 || curMonth == 6 ||
                   curMonth == 9 || curMonth == 11
        ) {
            daysInMonth = 30;
        } else {
            daysInMonth = 31;
        }
        if (curMonth == 12 && curDay == daysInMonth) {
            curMonth = 1;
            curDay = 0;
            curYear++;
        }
        if (curDay == daysInMonth) {
            curDay = 0;
            curMonth++;
        }
        curDay++;
        dayOfWeek = (dayOfWeek + 1) % 7;
    }
    if (dayOfWeek == 0) {
        printf("Monday");
    } else if (dayOfWeek == 1) {
        printf("Tuesday");
    } else if (dayOfWeek == 2) {
        printf("Wednesday");
    } else if (dayOfWeek == 3) {
        printf("Thursday");
    } else if (dayOfWeek == 4) {
        printf("Friday");
    } else if (dayOfWeek == 5) {
        printf("Saturday");
    } else {
        printf("Sunday");
    }
    printf(", %02d.%02d", curDay, curMonth);
    return 0;
}