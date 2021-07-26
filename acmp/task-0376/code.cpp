#include <stdio.h>

// Time complexity: O(n * log(n))
// Space complexity: O(1)

int main() {
    int endDay, endMonth;
    scanf("%d %d", &endDay, &endMonth);
    int startDay, startMonth;
    scanf("%d %d", &startDay, &startMonth);
    int year;
    scanf("%d", &year);
    int days = 0;
    while (startDay != endDay || startMonth != endMonth) {
        startDay++;
        if ((startMonth == 4 || startMonth == 6 ||
             startMonth == 9 || startMonth == 11) &&
            startDay == 31 || startDay == 32
            ) {
            startDay = 1;
            startMonth++;
        } else if (startMonth == 2) {
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                if (startDay == 30) {
                    startDay = 1;
                    startMonth++;
                }
            } else if (startDay == 29) {
                startDay = 1;
                startMonth++;
            }
        }
        if (startMonth == 13) {
            startMonth = 1;
            year++;
        }
        days++;
    }
    printf("%d", days);
    return 0;
}