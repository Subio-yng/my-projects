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
    std::vector<int> leftId = {0};
    for (int i = 1; i < n - 1; i++) {
        if (sequence[leftId.back()] <= sequence[i]) {
            leftId.push_back(i);
        }
    }
    std::vector<int> rightId;
    for (int i = n - 1; i > leftId.back(); i--) {
        if (i == n - 1 || sequence[rightId.back()] <= sequence[i]) {
            rightId.push_back(i);
        }
    }
    printf("%d\n", leftId.size() + rightId.size());
    for (int i = 0; i < (int) leftId.size(); i++) {
        printf("%d ", sequence[leftId[i]]);
    }
    for (int i = (int) rightId.size() - 1; i >= 0; i--) {
        printf("%d ", sequence[rightId[i]]);
    }
    return 0;
}