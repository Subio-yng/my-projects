#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

struct Event {

    int point;

    int val;
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Event> pipes;
    for (int i = 0; i < n; i++) {
        int left, right, val;
        scanf("%d %d %d", &left, &right, &val);
        pipes.push_back({left, val});
        pipes.push_back({right, -val});
    }
    int qPoint;
    scanf("%d", &qPoint);
    pipes.push_back({qPoint, 0});
    std::sort(pipes.begin(), pipes.end(), [](const Event &left, const Event &right) {
        if (left.point == right.point) {
            return left.val < right.val;
        }
        return left.point < right.point;
    });
    if (pipes[0].point == qPoint) {
        printf("0");
        return 0;
    }
    long long curSum = 0;
    long long curVol = pipes[0].val;
    for (int i = 1; i < (int) pipes.size(); i++) {
        curSum = std::max(0LL, curSum + curVol * (pipes[i].point - pipes[i - 1].point));
        curVol += pipes[i].val;
        if (pipes[i].point == qPoint) {
            break;
        }
    }
    printf("%lld", curSum);
    return 0;
}
