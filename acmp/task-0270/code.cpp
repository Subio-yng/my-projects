#include <stdio.h>
#include <string>

// Time complexity: O(len(variable))
// Space complexity: O(1)

int main() {
    char buf[1 + 100];
    scanf("%s", &buf);
    std::string variable(buf);
    bool c = false;
    bool java = false;
    for (int i = 1; i < (int) variable.length(); i++) {
        if (variable[i] == '_') {
            c = true;
            if (variable[i - 1] == '_') {
                printf("Error!");
                return 0;
            }
        }
        if ('A' <= variable[i] && variable[i] <= 'Z') {
            java = true;
        }
    }
    if (c && java || !('a' <= variable[0] && variable[0] <= 'z') || variable.back() == '_') {
        printf("Error!");
    } else if (c) {
        printf("%c", variable[0]);
        for (int i = 1; i < (int) variable.length(); i++) {
            if (variable[i - 1] == '_') {
                printf("%c", variable[i] - 32);
            } else if (variable[i] != '_') {
                printf("%c", variable[i]);
            }
        }
    } else if (java) {
        for (int i = 0; i < (int) variable.length(); i++) {
            if ('A' <= variable[i] && variable[i] <= 'Z') {
                printf("_%c", variable[i] + 32);
            } else {
                printf("%c", variable[i]);
            }
        }
    } else {
        printf("%s", variable.c_str());
    }
    return 0;
}