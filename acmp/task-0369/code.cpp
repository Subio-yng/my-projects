#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n^2)
// Space complexity: O(n)

struct Gangster {

    int time;

    int wealth;

    int fullness;
};

int main() {
    int n;
    scanf("%d %*d %*d", &n);
    std::vector<Gangster> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i].time);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i].wealth);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i].fullness);
    }
    std::sort(list.begin(), list.end(), [](const Gangster &left, const Gangster &right) {
        return left.time < right.time;
    });
    std::vector<int> maxSum(n, 0);
    for (int cur = 0; cur < n; cur++) {
        if (list[cur].fullness <= list[cur].time) {
            maxSum[cur] = list[cur].wealth;
            for (int prev = 0; prev < cur; prev++) {
                if (abs(list[prev].fullness - list[cur].fullness) <= list[cur].time - list[prev].time) {
                    maxSum[cur] = std::max(maxSum[cur], maxSum[prev] + list[cur].wealth);
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        max = std::max(max, maxSum[i]);
    }
    printf("%d", max);
    return 0;
}