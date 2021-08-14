#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

struct Runner {

    int speed;

    int step;

    int number;
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Runner> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &list[i].speed, &list[i].step);
        list[i].number = i;
    }
    std::sort(list.begin(), list.end(), [](const Runner &left, const Runner &right) {
        return left.step < right.step;
    });
    std::vector<long long> ans(n, 0);
    for (int i = 0; i < n; i++) {
        ans[list[i].number] = (long long) list[i].step * list[i].speed;
        if (i > 0 && ans[list[i - 1].number] > ans[list[i].number]) {
            ans[list[i].number] = ans[list[i - 1].number];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}