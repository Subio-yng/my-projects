#include <stdio.h>
#include <string>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    const int N = 4;
    char buf[1 + 30];
    scanf("ping %s", &buf);
    std::string name(buf);
    int sent = 0;
    int received = 0;
    int lost = 0;
    int max = INT_MIN;
    int min = INT_MAX;
    double sumTime = 0;
    for (int i = 0; i < N; i++) {
        scanf(" %s ", &buf);
        std::string temp(buf);
        if (temp == "Time") {
            scanf("out");
            lost++;
        } else {
            int number;
            scanf("from %*s Time=%d", &number);
            if (number > max) {
                max = number;
            }
            if (number < min) {
                min = number;
            }
            sumTime += number;
            received++;
        }
        sent++;
    }
    printf("Ping statistics for %s:\n", name.c_str());
    printf("Packets: Sent = %d Received = %d Lost = %d (%d%% loss)\n", sent, received, lost, lost * (100 / sent));
    if (received > 0) {
        printf("Approximate round trip times:\n");
        printf("Minimum = %d Maximum = %d Average = %.0f", min, max, round(sumTime / received));
    }
    return 0;
}