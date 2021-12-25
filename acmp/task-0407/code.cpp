#include <stdio.h>
#include <vector>
#include <climits>

// Time complexity: O(n * k)
// Space complexity: O(k)

int main() {
    int nCoins;
    scanf("%d", &nCoins);
    std::vector<int> coins(nCoins);
    for (int i = 0; i < nCoins; i++) {
        scanf("%d", &coins[i]);
    }
    int reqSum;
    scanf("%d", &reqSum);
    std::vector<int> minCoins(reqSum + 1, INT_MAX - 1);
    minCoins[0] = 0;
    for (int curSum = 1; curSum <= reqSum; curSum++) {
        for (int curCoin = 0; curCoin < nCoins; curCoin++) {
            if (coins[curCoin] <= curSum) {
                minCoins[curSum] = std::min(minCoins[curSum], minCoins[curSum - coins[curCoin]] + 1);
            }
        }
    }
    if (minCoins[reqSum] == INT_MAX - 1) {
        printf("-1");
    } else {
        printf("%d", minCoins[reqSum]);
    }
    return 0;
}