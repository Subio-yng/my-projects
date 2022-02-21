#include <stdio.h>
#include <vector>
#include <algorithm>
 
// Time complexity: O(n * log(n))
// Space complexity: O(n)
 
int main() {
    int n, capacity;
    scanf("%d %d", &n, &capacity);
    std::vector<int> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    std::sort(list.begin(), list.end());
    int count = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        if (list[left] + list[right] <= capacity) {
            left++;
        }
        right--;
        count++;
    }
    printf("%d", count);
    return 0;
}