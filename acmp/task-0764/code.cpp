#include <stdio.h>
#include <unordered_map>
#include <math.h>
#include <algorithm>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::unordered_map<double, int> angles;
    for (int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        angles[std::atan2(x, y)]++;
    }
    int maxTarget = 0;
    for (auto now : angles) {
        maxTarget = std::max(maxTarget, now.second);
    }
    printf("%d", maxTarget);
    return 0;
}