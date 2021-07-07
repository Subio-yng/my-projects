#include <stdio.h>
#include <string>

// Time complexity: O(fileSize)
// Space complexity: O(buf)

int main() {
    const int N_USERS = 2;
    const std::string name1 = "Fedya";
    char buf[1 + 250];
    scanf("%*d:%*d:%*d: %s signed on", &buf);
    std::string name2(buf);
    int curUser = 0;
    bool first = true;
    while (first) {
        scanf("%*d:%*d:%*d: %[^\n]s", &buf);
        std::string terminatePhrase(buf);
        if (terminatePhrase == name2 + " signed off") {
            first = !first;
        } else {
            if (terminatePhrase.back() == '.') {
                terminatePhrase.back() = ',';
            } else if (terminatePhrase.back() != '!' && terminatePhrase.back() != '?') {
                terminatePhrase += ',';
            }
            printf("\"%s\" --- skazal ", terminatePhrase.c_str());
            if (curUser % 2 == 0) {
                printf("%s.\n", name1.c_str());
            } else {
                printf("%s.\n", name2.c_str());
            }
            curUser = N_USERS - 1 - curUser;
        }
    }
    return 0;
}