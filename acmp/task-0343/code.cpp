#include <bits/stdc++.h>

// Time complexity: O(sizeI * sizeJ + nQ)
// Space complexity: O(sizeI * sizeJ)

bool canPlace(int type, int sizeI, int sizeJ, int i, int j, std::vector<std::vector<bool>> &used) {
    for (int di = 0; di <= 1; di++) {
        for (int dj = 0; dj <= 1; dj++) {
            if (2 * di + dj == type) {
                continue;
            }
            int nextI = i + di;
            int nextJ = j + dj;
            if (nextI < 0 || sizeI <= nextI ||
                nextJ < 0 || sizeJ <= nextJ ||
                used[nextI][nextJ]
                ) {
                return false;
            }
        }
    }
    for (int di = 0; di <= 1; di++) {
        for (int dj = 0; dj <= 1; dj++) {
            if (2 * di + dj == type) {
                continue;
            }
            used[i + di][j + dj] = true;
        }
    }
    return true;
}

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<bool>> used(sizeI, std::vector<bool>(sizeJ, false));
    int nQ;
    scanf("%d", &nQ);
    int sum = 0;
    for (int iQ = 0; iQ < nQ; iQ++) {
        int type, i, j;
        scanf("%d %d %d", &type, &i, &j);
        if (canPlace(type - 1, sizeI, sizeJ, i - 1, j - 1, used)) {
            sum += 3;
        }
    }
    printf("%d", sum);
    return 0;
}