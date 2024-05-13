#include <bits/stdc++.h>

// Time complexity: O(len)
// Space complexity: O(len)

bool inRange(char c1, char c2) {
    return 'a' + (c1 - '3') <= c2 && c2 <= 'd' + (c1 - '3');
}

int main() {
    char buf[1 + 9];
    scanf(" %s", &buf);
    std::string str1(buf);
    scanf(" %s", &buf);
    std::string str2(buf);
    int cnt = 1;
    for (int i = 0; i < (int) str1.length(); i++) {
        char c1 = str1[i];
        char c2 = str2[i];
        if (c1 > c2) {
            std::swap(c1, c2);
        }
        if (c1 < c2 && c2 <= '9' ||
            '0' <= c1 && c1 <= '9' &&
            'a' <= c2 && c2 <= 'g' &&
            !inRange(c1, c2)
        ) {
            cnt = 0;
            break;
        } else if (c1 == '?') {
            if (c2 == '?') {
                cnt *= 10;
            } else {
                cnt *= 4;
            }
        } else if ('a' <= c1 && c1 <= 'g') {
            cnt *= 4 - std::min(4, c2 - c1);
        }
    }
    printf("%d", cnt);
    return 0;
}