#include <stdio.h>
#include <vector>
#include <string>

// Time complexity: O(n^2)
// Space complexity: O(len)

int main() {
    const int ALPHABET_SIZE = 26;
    int n, nWords;
    scanf("%d %d", &n, &nWords);
    std::vector<int> cnt(ALPHABET_SIZE, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char val;
            scanf(" %c", &val);
            cnt[val - 'A']++;
        }
    }
    for (int w = 0; w < nWords; w++) {
        char buf[1 + 100];
        scanf(" %s", &buf);
        std::string curWord(buf);
        for (int i = 0; i < (int) curWord.length(); i++) {
            cnt[curWord[i] - 'A']--;
        }
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            printf("%c", 'A' + i);
        }
    }
    return 0;
}