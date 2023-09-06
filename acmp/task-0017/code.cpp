#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(n)

std::vector<int> getZFunction(const std::vector<int> &array, int n) {
    std::vector<int> z(n, 0);
    int left = 0;
    int right = 0;
    for (int i = 1; i < n; i++) {
        if (i <= right) {
            z[i] = std::min(right - i + 1, z[i - left]);
        }
        while (z[i] + i < n && array[z[i]] == array[z[i] + i]) {
            z[i]++;
        }
        if (z[i] + i - 1 > right) {
            left = i;
            right = z[i] + i - 1;
        }
    }
    return z;
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    std::vector<int> z = getZFunction(array, n);
    for (int i = 1; i < n; i++) {
        if ((n - 1) % i == 0 && z[i] == n - i) {
            printf("%d", i);
            return 0;
        }
    }
    throw 1;
}