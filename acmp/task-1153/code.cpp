#include <stdio.h>

// Time complexity: O(buf)
// Space complexity: O(1)

bool isVowel(char a) {
    return a == 'a' || a == 'e' || a == 'o' ||
        a == 'i' || a == 'y' || a == 'u';
}

int main() {
    int countChanges = 0;
    int countVowels = 0;
    int countConsonants = 0;
    while (true) {
        char buf;
        int code = scanf("%c", &buf);
        if (code == EOF || buf == '\n') {
            break;
        }
        if (isVowel(buf)) {
            countVowels++;
            countConsonants = 0;
        } else {
            countConsonants++;
            countVowels = 0;
        }
        if (countConsonants == 3) {
            countChanges++;
            countConsonants = 1;
        }
        if (countVowels == 3) {
            countChanges++;
            countVowels = 1;
        }
    }
    printf("%d", countChanges);
    return 0;
}