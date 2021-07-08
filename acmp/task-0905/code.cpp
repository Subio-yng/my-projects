#include <stdio.h>
#include <vector>
#include <string>

// Time complexity: O(n * len(str))
// Space complexity: O(n)

int main() {
    const int ALPHABET_SIZE = 26;
    const std::string KEY_PHRASE = "the quick brown fox jumps over the lazy dog";
    int n;
    scanf("%d", &n);
    std::vector<std::string> letter(n);
    for (int i = 0; i < n; i++) {
        char buf[1 + 250];
        scanf("%*c%[^\n]s", &buf);
        letter[i] = buf;
    }
    for (int i = 0; i < n; i++) {
        if (letter[i].length() == KEY_PHRASE.length()) {
            std::string curPhrase;
            std::vector<char> curReplacement(ALPHABET_SIZE, 0);
            for (int j = 0; j < letter[i].length(); j++) {
                if (letter[i][j] != ' ') {
                    if (curReplacement[letter[i][j] - 'a'] == 0) {
                        curReplacement[letter[i][j] - 'a'] = KEY_PHRASE[j];
                    }
                    curPhrase += curReplacement[letter[i][j] - 'a'];
                } else {
                    curPhrase += ' ';
                }
            }
            if (curPhrase == KEY_PHRASE) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < letter[j].length(); k++) {
                        if ('a' <= letter[j][k] && letter[j][k] <= 'z') {
                            printf("%c", curReplacement[letter[j][k] - 'a']);
                        } else {
                            printf("%c", letter[j][k]);
                        }
                    }
                    printf("\n");
                }
                return 0;
            }
        }
    }
    printf("No solution");
    return 0;
}