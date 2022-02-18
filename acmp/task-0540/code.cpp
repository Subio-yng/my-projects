#include <stdio.h>
#include <vector>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeJ)

int main() {
    int sizeI, sizeJ, mod;
    scanf("%d %d %d", &sizeI, &sizeJ, &mod);
    std::vector<long long> prevPrevList(sizeJ);
    std::vector<long long> prevList(sizeJ);
    std::vector<long long> curList(sizeJ);
    for (int j = 0; j < sizeJ; j++) {
        scanf("%lld", &prevList[j]);
    }
    curList[0] = (prevList[0] + prevList[1]) % mod;
    for (int j = 1; j < sizeJ - 1; j++) {
        curList[j] = (prevList[j - 1] + prevList[j] + prevList[j + 1]) % mod;
    }
    curList[sizeJ - 1] = (prevList[sizeJ - 1] + prevList[sizeJ - 2]) % mod;
    for (int i = 2; i < sizeI; i++) {
        prevPrevList = prevList;
        prevList = curList;
        curList[0] = (prevList[0] + 2 * prevList[1]) % mod;
        for (int j = 1; j < sizeJ - 1; j++) {
            long long cur = 2 * prevList[j - 1] + prevList[j] + 2 * prevList[j + 1] - prevPrevList[j];
            if (i > 2) {
                cur -= prevPrevList[j];
            }
            curList[j] = (cur + 2 * mod) % mod;
        }
        curList[sizeJ - 1] = (prevList[sizeJ - 1] + 2 * prevList[sizeJ - 2]) % mod;
    }
    for (int j = 0; j < sizeJ; j++) {
        printf("%lld ", (curList[j] + mod) % mod);
    }
    return 0;
}