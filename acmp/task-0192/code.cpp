#include <stdio.h>
#include <algorithm>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    std::next_permutation(list.begin(), list.end());
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    return 0;
}