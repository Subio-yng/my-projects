#include <stdio.h>
#include <vector>
#include <string>

// Time complexity: O(len)
// Space complexity: O(len)

int main() {
    char buf[1 + 1000000];
    scanf("%s", &buf);
    std::string str(buf);
    std::vector<int> n((int) str.length(), 0);
    int i = 0, j = 1;
    while (j < (int) str.length()) {
        if (str[i] == str[j]) {
            n[j] = i + 1;
            j++;
            i++;
        } else if (i == 0) {
            n[j] = 0;
            j++;
        } else {
            i = n[i - 1];
        }
    }
    for (int i = 0; i < (int) n.size(); i++) {
        printf("%d ", n[i]);
    }
    return 0;
}