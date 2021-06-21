#include <stdio.h>
#include <vector>

// Time complexity: O(end - start)
// Space complexity: O(1)

struct Time {

    int hour;

    int minute;

    int second;

    bool operator <= (Time a) {
        if (a.hour != this->hour) {
            return this->hour < a.hour;
        }
        if (a.minute != this->minute) {
            return this->minute < a.minute;
        }
        return this->second <= a.second;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Time start;
    scanf("%d:%d:%d", &start.hour, &start.minute, &start.second);
    Time end;
    scanf("%d:%d:%d", &end.hour, &end.minute, &end.second);
    std::vector<int> cnt(10, 0);
    while (start <= end) {
        cnt[start.hour / 10]++;
        cnt[start.hour % 10]++;
        cnt[start.minute / 10]++;
        cnt[start.minute % 10]++;
        cnt[start.second / 10]++;
        cnt[start.second % 10]++;
        start.second++;
        if (start.second == 60) {
            start.second = 0;
            start.minute++;
        }
        if (start.minute == 60) {
            start.minute = 0;
            start.hour++;
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}