#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nCoin * (fullBank - emptyBank))
// Space complexity: O(nCoin)

struct Coin {

    int price;

    int weight;

    static Coin read() {
        int p, w;
        scanf("%d %d", &p, &w);
        return {p, w};
    }
};

struct Cell {

    int minSum;

    int maxSum;
};

int main() {
    const int INF = 900000000;
    int emptyBank, fullBank;
    scanf("%d %d", &emptyBank, &fullBank);
    int nCoin;
    scanf("%d", &nCoin);
    std::vector<Coin> coins(nCoin);
    for (int i = 0; i < nCoin; i++) {
        coins[i] = Coin::read();
    }
    std::vector<Cell> bank(fullBank - emptyBank + 1, {INF, -INF});
    bank[0] = {0, 0};
    for (int curBank = 1; curBank <= fullBank - emptyBank; curBank++) {
        for (int curCoin = 0; curCoin < nCoin; curCoin++) {
            if (coins[curCoin].weight <= curBank) {
                bank[curBank].maxSum = std::max(bank[curBank].maxSum,
                                                bank[curBank - coins[curCoin].weight].maxSum +
                                                coins[curCoin].price);
                bank[curBank].minSum = std::min(bank[curBank].minSum,
                                                bank[curBank - coins[curCoin].weight].minSum +
                                                coins[curCoin].price);
            }
        }
    }
    if (bank.back().minSum == INF || bank.back().maxSum == -INF) {
        printf("This is impossible.");
    } else {
        printf("%d %d", bank.back().minSum, bank.back().maxSum);
    }
    return 0;
}