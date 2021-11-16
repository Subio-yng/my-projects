#include <stdio.h>
#include <string>

// Time complexity: O(len)
// Space complexity: O(1)

bool isFirstClass(std::string str) {
    const int MAX_ACTION = 3 * 9 * 9 + 1;
    for (int j = 0; j < MAX_ACTION; j++) {
        int nextNumber = 0;
        for (int i = 0; i < (int) str.length(); i++) {
            nextNumber += (str[i] - '0') * (str[i] - '0');
        }
        str = std::to_string(nextNumber);
        if (str == "1") {
            break;
        }
    }
    return str == "1";
}

int main() {
    char buf[1 + 100];
    scanf("%s", &buf);
    if (isFirstClass(buf)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}