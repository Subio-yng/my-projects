#include <stdio.h>
#include <algorithm>
#include <vector>

// Time complexity: O(n! * n)
// Space complexity: O(n)

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    std::vector<int> list(n);
    for (int i = 0; i < n; i++) {
        list[i] = i + 1;
    }
    int count = 0;
    do {
        bool check = true;
        for (int i = 1; i < n; i++) {
            if (abs(list[i] - list[i - 1]) > k) {
                check = false;
                break;
            }
        }
        if (check) {
            count++;
        }
    } while (std::next_permutation(list.begin(), list.end()));
    printf("%d", count);
    return 0;
}