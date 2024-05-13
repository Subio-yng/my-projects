#include <bits/stdc++.h>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<long long>> field(sizeI + 1, std::vector<long long>(sizeJ + 1, 0));
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            field[i][j] = field[i - 1][j] + field[i][j - 1] - field[i - 1][j - 1] + i * j;
        }
    }
    printf("%lld", field[sizeI][sizeJ]);
    return 0;
}