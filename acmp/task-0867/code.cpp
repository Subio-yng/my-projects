#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
    int n, dist;
    scanf("%d %d", &n, &dist);
    std::vector<int> order(n);
    std::map<int, int> line;
    for (int i = 0; i < n; i++) {
        scanf("%d", &order[i]);
        line[order[i]] = i;
    }
    std::sort(order.begin(), order.end());
    std::vector<int> ans(n);
    int last = 0;
    for (int cur : order) {
        auto prev = line.find(cur);
        if (prev == line.end()) {
            continue;
        }
        auto next = prev;
        while (next != line.end()) {
            ans[next->second] = last;
            prev = next;
            next = line.upper_bound(next->first + dist);
            line.erase(prev);
        }
        last++;
    }
    printf("%d\n", last);
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}
