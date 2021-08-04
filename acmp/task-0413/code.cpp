#include <stdio.h>
#include <vector>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    std::vector<std::vector<char>> map(sizeI + 1, std::vector<char>(sizeJ + 1, '.'));
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            scanf(" %c", &map[i][j]);
        }
    }
    int count = 0;
    for (int i = 1; i <= sizeI; i++) {
        for (int j = 1; j <= sizeJ; j++) {
            if (map[i][j] == '#' &&
                map[i - 1][j] == '.' &&
                map[i][j - 1] == '.'
                ) {
                int lenght = 0;
                for (int tempJ = j; tempJ <= sizeJ; tempJ++) {
                    if (map[i][tempJ] == '#') {
                        lenght++;
                    } else {
                        break;
                    }
                }
                if (lenght + i - 1 <= sizeI) {
                    bool square = true;
                    for (int tempI = i + 1; tempI < i + lenght; tempI++) {
                        int curLength = 0;
                        for (int tempJ = j; tempJ < j + lenght; tempJ++) {
                            if (map[tempI][tempJ] == '#') {
                                curLength++;
                            } else {
                                break;
                            }
                        }
                        if (curLength != lenght) {
                            square = false;
                            break;
                        }
                    }
                    if (square) {
                        count++;
                    }
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}