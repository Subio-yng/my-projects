#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list(n);
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
        if (list[i] > max) {
            max = list[i];
        }
        if (list[i] < min) {
            min = list[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (list[i] == max) {
            printf("%d ", min);
        } else {
            printf("%d ", list[i]);
        }
    }
    return 0;
}