#include <stdio.h>
#include <vector>

// Time complexity: O(n * len)
// Space complexity: O(n * ALPHABET_SIZE)

int main() {
    const int ALPHABET_SIZE = 26;
    int n;
    scanf("%d ", &n);
    std::vector<std::vector<int>> dictionary(n, std::vector<int>(ALPHABET_SIZE, 0));
    char buf;
    for (int i = 0; i < n; i++) {
        scanf(" %c", &buf);
        while (buf != '\n') {
            dictionary[i][buf - 'a']++;
            scanf("%c", &buf);
        }
    }
    std::vector<int> word(ALPHABET_SIZE, 0);
    scanf(" %c", &buf);
    while (buf != '\n') {
        word[buf - 'a']++;
        scanf("%c", &buf);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool a = true;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (dictionary[i][j] > word[j]) {
                a = false;
                break;
            }
        }
        if (a) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}