#include <stdio.h>
#include <vector>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeJ)

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    int count = 0;
    std::vector<char> prevStr(sizeJ + 1, '.');
    for (int i = 0; i < sizeI; i++) {
        std::vector<char> curStr(sizeJ + 1, '.');
        for (int j = 1; j <= sizeJ; j++) {
            scanf(" %c", &curStr[j]);
            if (curStr[j] == '#' &&
                curStr[j - 1] == '.' &&
                prevStr[j] == '.'
            ) {
                count++;
            }
        }
        prevStr = curStr;
    }
    printf("%d", count);
    return 0;
}