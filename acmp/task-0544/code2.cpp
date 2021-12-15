#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<long long> step(n + 2);
    step[0] = 1;
    step[1] = 1;
    step[2] = 2;
    for (int i = 3; i <= n; i++) {
        step[i] = step[i - 1] + step[i - 2] + step[i - 3];
    }
    printf("%lld", step[n]);
    return 0;
}