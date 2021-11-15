#include <stdio.h>
#include <string>

// Time complexity: O(1)
// Space complexity: O(1)

std::string plus(std::string a, std::string b) {
    if (a.length() < b.length()) {
        swap(a, b);
    }
    for (int i = (int) a.length() - 1,
         j = (int) b.length() - 1;
         i >= 0; i--, j--
         ) {
        if (j >= 0) {
            a[i] += b[j] - '0';
        }
        if (a[i] > '9') {
            a[i] -= 10;
            if (i == 0) {
                a = "1" + a;
            } else {
                a[i - 1]++;
            }
        }
    }
    return a;
}

bool isFirstClass(std::string str) {
    const int MAX_ACTION = 10000;
    for (int j = 0; j < MAX_ACTION; j++) {
        std::string nextNumber;
        for (int i = 0; i < (int) str.length(); i++) {
            nextNumber = plus(std::to_string((str[i] - '0') * (str[i] - '0')), nextNumber);
        }
        str = nextNumber;
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