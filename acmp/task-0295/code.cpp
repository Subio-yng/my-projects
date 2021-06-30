#include <stdio.h>
#include <string>

// Time complexity: O(len(cipher) * len(part))
// Space complexity: O(len(cipher) + len(part))

int main() {
    const int ALPHABET_SIZE = 26;
    char buf[1 + 40];
    scanf("%s", &buf);
    std::string cipher(buf);
    scanf("%s", &buf);
    std::string part(buf);
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        std::string temp;
        for (int j = 0; j < (int) part.length(); j++) {
            if (part[j] + i > 'Z') {
                temp += part[j] + i + 'A' - 'Z' - 1;
            } else {
                temp += part[j] + i;
            }
        }
        if (cipher.find(temp) != -1) {
            for (int j = 0; j < (int) cipher.length(); j++) {
                if (cipher[j] - i < 'A') {
                    printf("%c", cipher[j] - i - 'A' + 'Z' + 1);
                } else {
                    printf("%c", cipher[j] - i);
                }
            }
            return 0;
        }
    }
    printf("IMPOSSIBLE");
    return 0;
}