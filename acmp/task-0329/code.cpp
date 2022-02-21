#include <stdio.h>
#include <vector>
#include <algorithm>
 
// Time complexity: O(n)
// Space complexity: O(n)
 
void printWay(std::vector<int> &list, int i) {
    if (i > 1) {
        if (list[i - 1] > list[i - 2]) {
            printWay(list, i - 1);
        } else {
            printWay(list, i - 2);
        }
    } 
    if (i != 0) {
        printf("%d ", i);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list(n + 1, 0);
    for (int cur = 1; cur <= n; cur++) {
        scanf("%d", &list[cur]);
        if (cur > 1) {
            list[cur] += std::max(list[cur - 1], list[cur - 2]);
        }
    }
    printf("%d\n", list[n]);
    printWay(list, n);
    return 0;
}