#include <stdio.h>
#include <vector>

// Time complexity: O(n1 + n2)
// Space complexity: O(range)

int main() {
    int MAXVAL = 100000;
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    std::vector<std::byte> list(MAXVAL + 1);
    for (int i = 0; i < n1; i++) {
        int val;
        scanf("%d", &val);
        list[val] = (std::byte) 1;
    }
    for (int i = 0; i < n2; i++) {
        int val;
        scanf("%d", &val);
        if (list[val] == (std::byte) 1) {
            list[val] = (std::byte) 2;
        }
    }
    for (int val = 0; val <= MAXVAL; val++) {
        if (list[val] == (std::byte) 2) {
            printf("%d ", val);
        }
    }
    return 0;
}