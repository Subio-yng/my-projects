#include <stdio.h>
#include <string>

// Time complexity: O(n)
// Space complexity: O(buf)

int main() {
    const std::string name = "Fedya";
    int hour, minute, second;
    char buf[1 + 250];
    scanf("%d:%d:%d: %s signed on", &hour, &minute, &second, &buf);
    std::string nameInterlocutor(buf);
    int n = 1;
    while (true) {
        int hour, minute, second;
        scanf("%d:%d:%d: ", &hour, &minute, &second);
        char buf[1 + 250];
        scanf("%[^\n]s", &buf);
        std::string phrase(buf);
        if (phrase == nameInterlocutor + " signed off") {
            break;
        }
        if (phrase.back() == '.') {
            phrase.back() = ',';
        } else if (phrase.back() != '!' && phrase.back() != '?') {
            phrase += ',';
        }
        printf("\"%s\" --- skazal ", phrase.c_str());
        if (n % 2 == 0) {
            printf("%s.\n", nameInterlocutor.c_str());
        } else {
            printf("%s.\n", name.c_str());
        }
        n++;
    }
    return 0;
}