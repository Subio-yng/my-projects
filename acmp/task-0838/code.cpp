#include <stdio.h>

// Time complexity: O(code)
// Space complexity: O(1)

int main() {
    freopen("intput.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int PARENTHESIS = 1;
    const int COMMA = 2;
    const int SPECIALCHAR = 3;
    const int SPACE = 4;
    const int POINT = 5;
    const int SEMICOLON = 7;
    const int BRACKET = 8;
    const int SHIFT = 10;
    const int NUMBER = 13;
    int sumJoule = 0;
    while (true) {
        char buf;
        int code = scanf("%c", &buf);
        if (code == EOF) {
            break;
        }
        if (buf == '(' || buf == ')') {
            sumJoule += PARENTHESIS;
        }
        if (buf == ',') {
            sumJoule += COMMA;
        }
        if (buf == '+' || buf == '-' ||
            buf == '\'' || buf == '\"' || buf == '='
            ) {
            sumJoule += SPECIALCHAR;
        }
        if (buf == ' ') {
            sumJoule += SPACE;
        }
        if (buf == '.') {
            sumJoule += POINT;
        }
        if (buf == ';') {
            sumJoule += SEMICOLON;
        }
        if (buf == '[' || buf == ']' ||
            buf == '{' || buf == '}' ||
            buf == '<' || buf == '>'
            ) {
            sumJoule += BRACKET;
        }
        if (buf >= 'A' && buf <= 'Z') {
            buf++;
            sumJoule += (buf - 'A') % 10 + (buf - 'A') / 10 + SHIFT;
        }
        if (buf >= 'a' && buf <= 'z') {
            buf++;
            sumJoule += (buf - 'a') % 10 + (buf - 'a') / 10;
        }
        if (buf >= '0' && buf <= '9') {
            sumJoule += NUMBER - (buf - '0');
        }
    }
    printf("%d", sumJoule);
    return 0;
}