#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n + maxY)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    int maxY = 0;
    std::vector<int> leftX(51, 0);
    leftX[0] = 1;
    std::vector<int> rightX(51, 0);
    rightX[0] = 1;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        maxY = std::max(maxY, y);
        rightX[y] = std::max(x, rightX[y]);
        if (x < leftX[y] || leftX[y] == 0) {
            leftX[y] = x;
        }
    }
    std::vector<int> distLeft(maxY + 1);
    distLeft[0] = -1;
    std::vector<int> distRight(maxY + 1);
    distRight[0] = -1;
    for (int y = 1; y <= maxY; y++) {
        if (leftX[y] > 0) {
            distLeft[y] = rightX[y] - leftX[y] + std::min(
                distLeft[y - 1] + abs(rightX[y] - leftX[y - 1]),
                distRight[y - 1] + abs(rightX[y] - rightX[y - 1])
            );
            distRight[y] = rightX[y] - leftX[y] + std::min(
                distLeft[y - 1] + abs(leftX[y] - leftX[y - 1]),
                distRight[y - 1] + abs(leftX[y] - rightX[y - 1])
            );
        } else {
            leftX[y] = leftX[y - 1];
            rightX[y] = rightX[y - 1];
            distLeft[y] = distLeft[y - 1];
            distRight[y] = distRight[y - 1];
        }
        distLeft[y]++;
        distRight[y]++;
    }
    printf("%d", std::min(distRight[maxY], distLeft[maxY]));
    return 0;
}