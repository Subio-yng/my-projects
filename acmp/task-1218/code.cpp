#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> line(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &line[i]);
    }
    int val;
    scanf("%d", &val);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (val <= line[i]) {
            ans++;
        } else {
            break;
        }
    }
    printf("%d", ans);
    return 0;
}