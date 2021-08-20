#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }
    std::vector<int> left = {sequence[0]};
    for (int i = 1; i < n; i++) {
        if (left.back() <= sequence[i]) {
            left.push_back(sequence[i]);
        }
    }
    std::vector<int> right;
    for (int i = n - 1; sequence[i] < left.back(); i--) {
        if (i == n - 1 || right.back() <= sequence[i]) {
            right.push_back(sequence[i]);
        }
    }
    printf("%d\n", left.size() + right.size());
    for (int i = 0; i < (int) left.size(); i++) {
        printf("%d ", left[i]);
    }
    for (int i = (int) right.size() - 1; i >= 0; i--) {
        printf("%d ", right[i]);
    }
    return 0;
}