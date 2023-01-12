#include <bits/stdc++.h>

// Time complexity: O(len^2)
// Space complexity: O(len)

std::string getStr0(std::string str) {
    for (char next : str) {
        if (next != str[0]) {
            if (next > str[0]) {
                str[0]++;
            }
            break;
        }
    }
    for (char &next : str) {
        next = str[0];
    }
    return str;
}

int main() {
    char buf[1 + 17];
    scanf(" %s", &buf);
    char type;
    scanf(" %c", &type);
    std::string str = getStr0(buf);
    std::string start(buf);
    if (type == '0') {
        printf("%s", str.c_str());
        return 0;
    }
    int len = (int) start.length();
    for (int i = 0; i < len; i++) {
        std::string cur;
        if (i == 0) {
            cur = start[0] + getStr0(start.substr(1, len - 1));
        } else {
            char tmp = start[i];
            start[i] = '0';
            cur = getStr0(start);
            start[i] = tmp;
            cur[i] = '0';
            while (cur < start && cur[i] < '9') {
                cur[i]++;
            }
        }
        if (cur < start) {
            continue;
        }
        str = std::min(str, cur);
    }
    printf("%s", str.c_str());
    return 0;
}