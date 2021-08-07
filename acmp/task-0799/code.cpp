#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    int maxScoreId = 0;
    int score = 0;
    for (int i = 1; i < n - 1; i++) {
        if (list[i] % 10 == 5 && list[i + 1] < list[i] &&
            maxScoreId < i && list[i] > score
        ) {
            score = list[i];
        }
        if (list[i] > list[maxScoreId]) {
            maxScoreId = i;
            score = 0;
        }
    }
    if (score == 0) {
        printf("0");
    } else {
        int place = 1;
        for (int i = 0; i < n; i++) {
            if (list[i] > score) {
                place++;
            }
        }
        printf("%d", place);
    }
    return 0;
}