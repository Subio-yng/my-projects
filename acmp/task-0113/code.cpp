#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> maxSquare(n + 1, std::vector<int>(n + 1, 0));
    int maxSquareLen = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char curCell;
            scanf(" %c", &curCell);
            if (curCell == '1') {
                maxSquare[i][j] = std::min({maxSquare[i - 1][j - 1], maxSquare[i - 1][j], maxSquare[i][j - 1]}) + 1;
                maxSquareLen = std::max(maxSquareLen, maxSquare[i][j]);
            }
        }
    }
    printf("%d", maxSquareLen * maxSquareLen);
    return 0;
}