#include <bits/stdc++.h>

int main() {
    const std::vector<std::vector<int>> NUM = {{0, 0, 0, 0},
                                               {1, 1, 1, 1},
                                               {2, 4, 8, 6},
                                               {3, 9, 7, 1},
                                               {4, 6, 4, 6},
                                               {5, 5, 5, 5},
                                               {6, 6, 6, 6},
                                               {7, 9, 3, 1},
                                               {8, 4, 2, 6},
                                               {9, 1, 9, 1}};
    char buf[1 + 41];
    scanf(" %s", &buf);
    int id = std::string(buf).back() - '0';
    scanf(" %s", &buf);
    std::string str(buf);
    int pow = str.back() - '0';
    if (1 < (int) str.length()) {
        pow += (str[(int) str.length() - 2] - '0') * 10;
    }
    printf("%d", NUM[id][(pow + 3) % 4]);
    return 0;
}