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
    while (curDay != endDay || curMonth != endMonth) {
        int daysInFebruary;
        if (curYear % 4 == 0 && curYear % 100 != 0 || curYear % 400 == 0) {
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
        days++;
    }
    printf("%d", days);
    return 0;
}