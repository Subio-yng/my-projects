#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int day, month, week;
    scanf("%d %d %d", &day, &month, &week);
    int curD, curM, curY;
    scanf("%d %d %d", &curD, &curM, &curY);
    curM--;
    curY--;
    curD--;
    printf("%c", 'a' + (1LL * curY * month * day + curM * day + curD) % week);
    return 0;
}