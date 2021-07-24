#include <stdio.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> price(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    int money = 0;
    int prevDay = 0;
    for (int i = 0; i < n; i++) {
        int max = 0;
        int day = 0;
        for (int j = i; j < n; j++) {
            if (price[j] > max) {
                max = price[j];
                day = j + 1;
            }
        }
        money += max * (day - prevDay);
        i = day - 1;
        prevDay = day;
    }
    printf("%d", money);
    return 0;
}