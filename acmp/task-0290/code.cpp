#include <stdio.h>
#include <vector>

// Time complexity: O(sizeBase * sizeMap)
// Space complexity: O(sizeMap)

int main() {
    int sizeBaseI, sizeBaseJ;
    scanf("%d %d", &sizeBaseI, &sizeBaseJ);
    std::vector<std::vector<char>> base(sizeBaseI, std::vector<char>(sizeBaseJ));
    for (int i = 0; i < sizeBaseI; i++) {
        for (int j = 0; j < sizeBaseJ; j++) {
            scanf(" %c", &base[i][j]);
        }
    }
    int sizeMapI, sizeMapJ;
    scanf("%d %d", &sizeMapI, &sizeMapJ);
    std::vector<std::vector<char>> map(sizeMapI, std::vector<char>(sizeMapJ));
    for (int i = 0; i < sizeMapI; i++) {
        for (int j = 0; j < sizeMapJ; j++) {
            scanf(" %c", &map[i][j]);
        }
    }
    int count = 0;
    for (int iMap = 0; iMap + sizeBaseI <= sizeMapI; iMap++) {
        for (int jMap = 0; jMap + sizeBaseJ <= sizeMapJ; jMap++) {
            bool ans = true;
            for (int iBase = 0; iBase < sizeBaseI && ans; iBase++) {
                for (int jBase = 0; jBase < sizeBaseJ; jBase++) {
                    if (base[iBase][jBase] == '#' &&
                        map[iBase + iMap][jBase + jMap] == '.'
                    ) {
                        ans = false;
                        break;
                    }
                }
            }
            if (ans) {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}