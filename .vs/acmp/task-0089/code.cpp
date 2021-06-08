#include <stdio.h>
#include <string>
#include <math.h>

// Time complexity: O(n)
// Space complexity: O(buf)

const int DAY = 1440;
const double DISTANCE = 39000;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    double maxSpeed = -1;
    std::string fastest;
    for (int i = 0; i < n; i++) {
        char buf[1 + 50];
        scanf(" \"%[^\"]s", &buf);
        char hour1[2], minute1[2], hour2[2], minute2[2];
        scanf("\" %c%c:%c%c", &hour1[0], &hour1[1], &minute1[0], &minute1[1]);
        scanf(" %c%c:%c%c", &hour2[0], &hour2[1], &minute2[0], &minute2[1]);
        int time = ((hour2[0] - '0') * 10 + hour2[1] - '0') * 60 + (minute2[0] - '0') * 10 + minute2[1] - '0';
        time -= ((hour1[0] - '0') * 10 + hour1[1] - '0') * 60 + (minute1[0] - '0') * 10 + minute1[1] - '0';
        double speed;
        if (time <= 0) {
            time += DAY;
        }
        speed = DISTANCE / time;
        if (speed > maxSpeed) {
            maxSpeed = speed;
            fastest = buf;
        }
    }
    printf("The fastest train is \"");
    for (int i = 0; i < (int) fastest.length(); i++) {
        printf("%c", fastest[i]);
    }
    printf("\".\nIts speed is %.0f km/h, approximately.", round(maxSpeed));
    return 0;
}