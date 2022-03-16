#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
 
// Time complexity: O(n)
// Space complexity: O(n)
 
int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list(n);
    int sum = 0;
    int minI = 0;
    int maxI = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
        if (list[i] > 0) {
            sum += list[i];
        }
        if (list[minI] > list[i]) {
            minI = i;
        }
        if (list[maxI] < list[i]) {
            maxI = i;
        }
    }
    int mult = 1;
    int left = std::min(minI, maxI) + 1;
    int right = std::max(minI, maxI);
    while (left != right) {
        mult *= list[left];
        left++;
    }
    printf("%d %d", sum, mult);
    return 0;
}