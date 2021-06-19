#include <stdio.h>
#include <algorithm>
#include <string>

// Time complexity: O(n * len(str))
// Space complexity: O(buf)

int main() {
    freopen("intput.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int MAXSIZE = 1023;
    char buf[1 + 1000];
    scanf("%s", &buf);
    std::string str(buf);
    int n;
    scanf("%d", &n);
    if (n > 0) {
        for (int i = 0; i < std::min(n * (int) str.length(), MAXSIZE); i++) {
            printf("%c", str[i % (int) str.length()]);
        }
    } else {
        n = n * -1 - 1;
        std::string root;
        for (int i = 0; i < (int) str.length() >> n; i++) {
            root += str[i];
        }
        std::string temp;
        for (int i = 0; i <= n; i++) {
            temp += root;
        }
        if (temp == str) {
            printf("%s", root.c_str());
        } else {
            printf("NO SOLUTION");
        }
    }
    return 0;
}