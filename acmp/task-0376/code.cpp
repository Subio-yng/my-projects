#include <stdio.h>

// Time complexity: O(end - start)
// Space complexity: O(1)

int main() {
    int endDay, endMonth;
    scanf("%d %d", &endDay, &endMonth);
    int curDay, curMonth;
    scanf("%d %d", &curDay, &curMonth);
    int curYear;
    scanf("%d", &curYear);
    int days = 0;
    int daysInFebruary;
    if (curYear % 4 == 0 && curYear % 100 != 0 || curYear % 400 == 0) {
        daysInFebruary = 29;
    } else {
        daysInFebruary = 28;
    }
    while (curDay != endDay || curMonth != endMonth) {
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
        if (curDay == daysInMonth) {
            curDay = 0;
            curMonth++;
        }
        if (curMonth == 13) {
            curMonth = 1;
            curYear++;
            if (curYear % 4 == 0 && curYear % 100 != 0 || curYear % 400 == 0) {
                daysInFebruary = 29;
            } else {
                daysInFebruary = 28;
            }
        }
        curDay++;
        days++;
    }
    printf("%d", days);
    return 0;
}