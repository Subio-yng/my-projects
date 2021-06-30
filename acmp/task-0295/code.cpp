#include <stdio.h>
#include <string>

// Time complexity: O(len(part))
// Space complexity: O(buf)

int main() {
    const int MAXDENOMINATOR = 25;
    char buf[1 + 40];
    scanf("%s", &buf);
    std::string cipher(buf);
    scanf("%s", &buf);
    std::string part(buf);
    bool ans = true;
    for (int i = 0; i <= MAXDENOMINATOR; i++) {
        std::string temp;
        for (int j = 0; j < (int) part.length(); j++) {
            if (part[j] + i > 'Z') {
                temp += 'A' + part[j] + i - 'Z' - 1;
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
            ans = false;
            break;
        }
    }
    if (ans) {
        printf("IMPOSSIBLE");
    }
    return 0;
}