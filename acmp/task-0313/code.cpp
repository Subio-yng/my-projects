#include <stdio.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<int> bus(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bus[i]);
    }
    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        int tempTime = 0;
        for (int j = i + 1; j < n; j++) {
            tempTime++;
            if (bus[j] == bus[i]) {
                if (tempTime > maxTime) {
                    maxTime = tempTime;
                }
                break;
            }
        }
    }
    printf("%d", maxTime);
    return 0;
}