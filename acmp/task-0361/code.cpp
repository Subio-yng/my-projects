#include <stdio.h>
#include <string>
#include <vector>

// Time complexity: O(len(str))
// Space complexity: O(1)

int main() {
    const int ALPHABET_SIZE = 26;
    char buf[1 + 100];
    scanf("%s", &buf);
    std::string str(buf);
    int maxLen = 0;
    std::vector<int> words(ALPHABET_SIZE, -1);
    for (int i = 0; i < (int) str.length(); i++) {
        if (words[str[i] - 'a'] == -1) {
            words[str[i] - 'a'] = i;
        } else if (i - words[str[i] - 'a'] > maxLen) {
            maxLen = i - words[str[i] - 'a'];
        }
    }
    printf("%d", maxLen);
    return 0;
}