#include <bits/stdc++.h>

// Time complexity: O(n^2)
// Space complexity: O(n)

struct Mushroom {

    int x;

    int y;

    int r;

    static Mushroom read() {
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);
        return {x, y, r};
    }

    double getDist(const Mushroom &a) const {
        int dx = x - a.x;
        int dy = y - a.y;
        return (sqrt(dx * dx + dy * dy) - a.r - r) / 2.0;
    }
};

int main() {
    int n, maxSize;
    scanf("%d %d", &n, &maxSize);
    std::vector<Mushroom> field(n);
    for (int i = 0; i < n; i++) {
        field[i] = Mushroom::read();
    }
    double minSize = 1.0 * maxSize;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            minSize = std::min(minSize, field[i].getDist(field[j]));
        }
    }
    printf("%.2f", std::max(0.0, minSize));
    return 0;
}
