#include <stdio.h>
#include <unordered_set>
#include <math.h>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::unordered_set<double> function;
    for (int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        function.insert(std::atan2(x, y));
    }
    printf("%d", (int) function.size());
    return 0;
}