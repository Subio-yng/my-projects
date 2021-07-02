#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> line(n);
    for (int i = 0; i < n; i++) {
        line[i] = i + 1;
    }
    int left, right;
    scanf("%d %d", &left, &right);
    left--;
    right--;
    std::reverse(line.begin() + left, line.begin() + right + 1);
    scanf("%d %d", &left, &right);
    left--;
    right--;
    std::reverse(line.begin() + left, line.begin() + right + 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", line[i]);
    }
    return 0;
}