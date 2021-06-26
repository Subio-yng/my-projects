#include <stdio.h>

// Time comeplexity: O(distance2 - distance1)
// Space complexity: O(1)

int main() {
    const int PERCENT = 15;
    double distance1, distance2;
    scanf("%lf %lf", &distance1, &distance2);
    distance1 *= 1000;
    distance2 *= 1000;
    int day = 1;
    while (distance1 < distance2) {
        distance1 += distance1 * PERCENT / 100;
        day++;
    }
    printf("%d", day);
    return 0;
}