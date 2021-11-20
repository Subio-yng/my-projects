#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list1(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list1[i]);
    }
    std::sort(list1.begin(), list1.end());
    std::vector<int> list2(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list2[i]);
    }
    std::sort(list2.begin(), list2.end());
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(list1[i] - list2[i]);
    }
    printf("%d", sum);
    return 0;
}