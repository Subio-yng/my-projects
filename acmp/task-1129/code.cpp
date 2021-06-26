#include <stdio.h>

// Time comeplexity: O(endMoney - startMoney)
// Space complexity: O(1)

int main() {
    int startMoney, percent, endMoney;
    scanf("%d %d %d", &startMoney, &percent, &endMoney);
    startMoney *= 100;
    endMoney *= 100;
    int years = 0;
    while (startMoney < endMoney) {
        startMoney += startMoney * percent / 100;
        years++;
    }
    printf("%d", years);
    return 0;
}