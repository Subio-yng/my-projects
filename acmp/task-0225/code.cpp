#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n)
// Space complexity: O(n)

struct Man {

    int oneTicket;

    int twoTicket;

    int threeTicket;

    static Man read() {
        Man a;
        scanf("%d %d %d", &a.oneTicket, &a.twoTicket, &a.threeTicket);
        return a;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Man> list(n + 2);
    for (int i = 1; i <= n; i++) {
        list[i] = Man::read();
    }
    std::reverse(list.begin(), list.end());
    std::vector<int> time(n + 2);
    time[0] = 0;
    time[1] = list[1].oneTicket;
    time[2] = std::min(time[1] + list[2].oneTicket, list[2].twoTicket);
    for (int cur = 3; cur <= n; cur++) {
        time[cur] = std::min({time[cur - 1] + list[cur].oneTicket,
                             time[cur - 2] + list[cur].twoTicket,
                             time[cur - 3] + list[cur].threeTicket});
    }
    printf("%d", time[n]);
    return 0;
}