#include <stdio.h>

// Time complexity: O(years)
// Space complexity: O(1)

int main() {
    int curRobots, years;
    scanf("%d %d", &curRobots, &years);
    int prevRobots1 = curRobots;
    int prevRobots2 = 0;
    int prevRobots3 = 0;
    for (int i = 1; i < years; i++) {
        int maxNewRobots = 0;;
        int tempRobots = curRobots;
        while (tempRobots > 2 && tempRobots % 5 != 0) {
            maxNewRobots += 5;
            tempRobots -= 3;
        }
        maxNewRobots += tempRobots / 5 * 9;
        curRobots += maxNewRobots - prevRobots3;
        prevRobots3 = prevRobots2;
        prevRobots2 = prevRobots1;
        prevRobots1 = maxNewRobots;
    }
    printf("%d", curRobots);
    return 0;
}