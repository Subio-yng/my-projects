#include <stdio.h>
#include <string>

// Time complexity: O(fileSize)
// Space complexity: O(buf)

int main() {
    const int N_USERS = 2;
    const std::string NAME1 = "Fedya";
    char buf[1 + 250];
    scanf("%*d:%*d:%*d: %s signed on", &buf);
    std::string name2(buf);
    std::string terminatePhrase = name2 + " signed off";
    int curUser = 0;
    while (true) {
        scanf("%*d:%*d:%*d: %[^\n]s", &buf);
        std::string phrase(buf);
        if (phrase == terminatePhrase) {
            break;
        }
        if (phrase.back() == '.') {
            phrase.back() = ',';
        } else if (phrase.back() != '!' && phrase.back() != '?') {
            phrase += ',';
        }
        printf("\"%s\" --- skazal ", phrase.c_str());
        if (curUser % 2 == 0) {
            printf("%s.\n", NAME1.c_str());
        } else {
            printf("%s.\n", name2.c_str());
        }
        curUser = N_USERS - 1 - curUser;
    }
    return 0;
}