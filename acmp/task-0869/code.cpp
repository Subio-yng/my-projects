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
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        if (i != j && list[i] + list[j] <= capacity) {
            i++;
            j--;
        } else {
            j--;
        }
        count++;
    }
    printf("%d", count);
    return 0;
}