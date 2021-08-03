#include <stdio.h>

// Time complexity: O(start - end)
// Space complexity: O(1)

struct Date {

    int day;

    int month;

    int year;

    static Date read() {
        Date a;
        scanf("%d.%d.%d", &a.day, &a.month, &a.year);
        return a;
    }
};

int main() {
    Date curDate = Date::read();
    Date endDate = Date::read();
    int days = 1;
    while (curDate.day != endDate.day ||
           curDate.month != endDate.month ||
           curDate.year != endDate.year
        ) {
        int daysInFebruary;
        if (curDate.year % 4 == 0 && curDate.year % 100 != 0 ||
            curDate.year % 400 == 0
        ) {
            daysInFebruary = 29;
        } else {
            daysInFebruary = 28;
        }
        int daysInMonth;
        if (curDate.month == 2) {
            daysInMonth = daysInFebruary;
        } else if (curDate.month == 4 || curDate.month == 6 ||
                   curDate.month == 9 || curDate.month == 11
        ) {
            daysInMonth = 30;
        } else {
            daysInMonth = 31;
        }
        if (curDate.month == 12 && curDate.day == daysInMonth) {
            curDate.month = 1;
            curDate.day = 0;
            curDate.year++;
        }
        if (curDate.day == daysInMonth) {
            curDate.day = 0;
            curDate.month++;
        }
        curDate.day++;
        days++;
    }
    printf("%d", days);
    return 0;
}