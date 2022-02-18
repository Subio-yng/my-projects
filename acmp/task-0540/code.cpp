#include <stdio.h>
#include <vector>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeJ)

int main() {
    int sizeI, sizeJ, mod;
    scanf("%d %d %d", &sizeI, &sizeJ, &mod);
    std::vector<long long> prevPrev(sizeJ);
    std::vector<long long> prev(sizeJ, 0);
    std::vector<long long> cur(sizeJ);
    for (int j = 0; j < sizeJ; j++) {
        scanf("%d", &cur[j]);
    }
    for (int i = 1; i < sizeI; i++) {
        prevPrev.swap(prev);
        prev.swap(cur);
        for (int j = 0; j < sizeJ; j++) {
            if (i == 1) {
                if (j == 0) {
                    cur[j] = (prev[j] + prev[j + 1]) % mod;
                } else if (j + 1 == sizeJ) {
                    cur[j] = (prev[j] + prev[j - 1]) % mod;
                } else {
                    cur[j] = (prev[j - 1] + prev[j] + prev[j + 1]) % mod;
                }
            } else if (i == 2) {
                if (j == 0) {
                    cur[j] = (prev[j] + 2 * prev[j + 1]) % mod;
                } else if (j + 1 == sizeJ) {
                    cur[j] = (prev[j] + 2 * prev[j - 1]) % mod;
                } else {
                    cur[j] = (2 * (prev[j - 1] + prev[j + 1]) - prevPrev[j] + prev[j]) % mod;
                }
            } else {
                if (j == 0) {
                    cur[j] = (prev[j] + 2 * prev[j + 1]) % mod;
                } else if (j + 1 == sizeJ) {
                    cur[j] = (prev[j] + 2 * prev[j - 1]) % mod;
                } else {
                    cur[j] = (2 * (prev[j - 1] + prev[j + 1] - prevPrev[j]) + prev[j]) % mod;
                }
            }
        }
    }
    for (int j = 0; j < sizeJ; j++) {
        printf("%lld ", (cur[j] + mod) % mod);
    }
    return 0;
}