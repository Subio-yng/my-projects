#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    std::vector<std::string> list(n);
    for (int i = 0; i < n; i++) {
        list[i] = std::to_string(i + 1);
    }
    std::sort(list.begin(), list.end());
    for (int i = 0; i < n; i++) {
        if (std::to_string(k) == list[i]) {
            printf("%d", i + 1);
        }
    }
    return 0;
}