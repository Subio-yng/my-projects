#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        if ((n - 1) % i != 0) {
            continue;
        }
        bool findAns = true;
        for (int j = i; j < n; j++) {
            if (arr[j] != arr[j - i]) {
                findAns = false;
                break;
            }
        }
        if (findAns) {
            printf("%d", i);
            return 0;
        }
    }
    throw 1;
}
