#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n, base;
    scanf("%d %d", &n, &base);
    std::vector<int> count(n + 1);
    count[1] = base - 1;
    count[2] = base * (base - 1);
    for (int i = 3; i <= n; i++) {
        count[i] = (count[i - 1] + count[i - 2]) * (base - 1);
    }
    printf("%d", count[n]);
    return 0;
}