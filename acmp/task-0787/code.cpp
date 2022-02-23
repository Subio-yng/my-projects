#include <stdio.h>
#include <vector>
#include <algorithm> 
  
// Time complexity: O(n^2)
// Space complexity: O(n^2)
 
int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> maxWin(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        scanf("%d", &maxWin[i][i]);
    }
    for (int iLen = 2; iLen <= n; iLen++) {
        for (int iLeft = 0; iLeft + iLen <= n; iLeft++) {
            int iRight = iLen + iLeft - 1;
            if ((iLen + n) % 2 == 0) {
                maxWin[iLeft][iRight] = std::max(maxWin[iLeft + 1][iRight],
                                                 maxWin[iLeft][iRight - 1]);
            } else {
                maxWin[iLeft][iRight] = std::min(maxWin[iLeft + 1][iRight],
                                                 maxWin[iLeft][iRight - 1]);
            }
        }
    }
    printf("%d", maxWin[0][n - 1]);
    return 0;
}