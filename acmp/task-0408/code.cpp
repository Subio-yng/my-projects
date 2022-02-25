#include <stdio.h>
#include <string>
#include <vector>
 
// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)
 
int main() {
    int sizeJ, sizeI;
    scanf("%d %d", &sizeJ, &sizeI);
    std::vector<std::string> letter(sizeI);
    bool check = false;
    for (int i = 0; i < sizeI; i++) {
        char buf[1 + 100];
        scanf(" %[^\n]s", &buf);
        letter[i] = buf;
        while (letter[i].back() == ' ') {
            letter[i].pop_back();
        }
        if (letter[i].length() > sizeJ) {
            check = true;
        }
    }
    if (check) {
        printf("Impossible.");
        return 0;
    }
    for (int i = 0; i < sizeI; i++) {
        int len = (int) letter[i].length();
        for (int j = 0; j < (sizeJ - len) / 2; j++) {
            printf(" ");
        }
        printf("%s", letter[i].c_str());
        for (int j = 0; j < (sizeJ - len + 1) / 2; j++) {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}