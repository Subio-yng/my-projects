#include <stdio.h>
#include <vector>

// Time complexity: O(move^2)
// Space complexity: O(move^2)

int main() {
    int n, move;
    scanf("%d %d", &n, &move);
    int size = n + (move - n) / 2;
    std::vector<std::vector<int>> ways(size, std::vector<int>(move + 1, 0));
    ways[size - n][0] = 1;
    for (int curMove = 1; curMove < move; curMove++) {
        for (int len = 0; len < size; len++) {
            if (len > 0) {
                ways[len][curMove] += ways[len - 1][curMove - 1];
            }
            if (len + 1 < size) {
                ways[len][curMove] += ways[len + 1][curMove - 1];
            }
        }
    }
    printf("%d", ways[size - 1][move - 1]);
    return 0;
}