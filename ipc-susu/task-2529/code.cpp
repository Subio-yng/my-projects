#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int n;

std::vector<int> read() {
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    return a;
}

bool checkLine(int line, int l1, int l2, int l3) {
    return l1 > 0 || l2 >= n || l3 >= n - line;
}

int main() {
    scanf("%d", &n);
    std::vector<int> left = read();
    std::vector<int> right = read();
    std::vector<int> top = read();
    std::vector<int> bottom = read();
    for (int i = 0; i < n; i++) {
        if (left[i] < n &&
            checkLine(left[i], top[left[i]] - i, bottom[left[i]] + i, right[i]) ||
            right[i] < n &&
            checkLine(right[i], top[n - right[i] - 1] - i, bottom[n - right[i] - 1] + i, left[i]) ||
            top[i] < n &&
            checkLine(top[i], left[top[i]] - i, right[top[i]] + i, bottom[i]) ||
            bottom[i] < n &&
            checkLine(bottom[i], left[n - bottom[i] - 1] - i, right[n - bottom[i] - 1] + i, top[i])
        ) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}