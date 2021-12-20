#include <stdio.h>
#include <vector>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n, mod;
    scanf("%d %d", &n, &mod);
    std::vector<int> word(n + 2, 0);
    word[1] = 0;
    word[2] = 1 % mod;
    for (int i = 2; i < n; i++) {
        word[i + 1] = (word[i + 1] + word[i]) % mod;
        if (i * 2 <= n) {
            word[i * 2] = (word[i * 2] + word[i]) % mod;
        }
    }
    printf("%d", word[n]);
    return 0;
}