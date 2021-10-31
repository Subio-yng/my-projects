#include <stdio.h>
#include <string>
#include <vector>

// Time complexity: O(len(str1))
// Space complexity: O(len(str1))

int main() {
    const int ALPHABET_SIZE = 26;
    char buf[1 + 100000];
    scanf("%s", &buf);
    std::string str1(buf);
    scanf(" %s", &buf);
    std::string str2(buf);
    std::vector<int> alphabet(ALPHABET_SIZE, 0);
    for (int i = 0; i < (int) str1.length(); i++) {
        if (str1[i] != str2[i]) {
            alphabet[str1[i] - 'A']++;
        }
        alphabet[str2[i] - 'A']++;
    }
    for (int i = 0; i < (int) str1.length(); i++) {
        if (alphabet[str1[i] - 'A'] >= alphabet[str2[i] - 'A']) {
            printf("%c", str1[i]);
            alphabet[str2[i] - 'A']--;
        } else {
            printf("%c", str2[i]);
            alphabet[str1[i] - 'A']--;
        }
    }
    return 0;
}