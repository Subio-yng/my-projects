#include <stdio.h>
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
    int left, right;
    scanf("%d %d", &left, &right);
    int max = INT_MIN;
    int num = 0;
    for (int i = left - 1; i < right; i++) {
        if (list[i] > max) {
            max = list[i];
            num = i + 1;
        }
    }
    printf("%d %d", max, num);
    return 0;
}