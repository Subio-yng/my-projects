#include <stdio.h>
#include <vector>

// Time complexity: O(n1 + n2)
// Space complexity: O(n1 + n2)

int main() {
    int MAXVAL = 100000;
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    std::vector<bool> list1(MAXVAL + 1, false);
    for (int i = 0; i < n1; i++) {
        int val;
        scanf("%d", &val);
        list1[val] = true;
    }
    std::vector<bool> list2(MAXVAL + 1, false);
    for (int i = 0; i < n2; i++) {
        int val;
        scanf("%d", &val);
        list2[val] = true;
    }
    for (int val = 0; val <= MAXVAL; val++) {
        if (list1[val] && list2[val]) {
            printf("%d ", val);
        }
    }
    return 0;
}