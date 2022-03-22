#include <stdio.h>
#include <vector>
#include <algorithm>
 
// Time complexity: O(n * log(n))
// Space complexity: O(n)
 
int main() {
    std::vector<int> list;
    int val;
    while (scanf("%d", &val) != EOF) {
        list.push_back(val);
    }
    std::sort(list.begin(), list.end());
    int diff = list[1] - list[0];
    for (int i = 2; i < (int) list.size(); i++) {
        if (list[i] - list[i - 1] != diff) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}