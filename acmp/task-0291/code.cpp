#include <stdio.h>
#include <vector>

// Time complexity: O(n * len)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d ", &n);
    std::vector<std::vector<int>> dictionary(n, std::vector<int>(26, 0));
    char buf;
    for (int i = 0; i < n; i++) {
        scanf(" %c", &buf);
        while (buf != '\n') {
            dictionary[i][buf - 'a']++;
            scanf("%c", &buf);
        }
    }
    std::vector<int> word(26, 0);
    scanf(" %c", &buf);
    while (buf != '\n') {
        word[buf - 'a']++;
        scanf("%c", &buf);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool a = true;
        for (int j = 0; j < 26; j++) {
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