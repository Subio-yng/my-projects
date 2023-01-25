#include <bits/stdc++.h>

// Time complexity: O(len)
// Space complexity: O(len)

void getPos(std::vector<std::vector<int>> &pos) {
    static char buf[1 + 100'000];
    scanf(" %s", &buf);
    std::string str(buf);
    for (int i = (int) str.length() - 1; i >= 0; i--) {
        pos[str[i] - 'a'].push_back(i);
    }
}

int main() {
    const int ALPHABET_SIZE = 26;
    std::vector<std::vector<int>> pos1(ALPHABET_SIZE);
    getPos(pos1);
    std::vector<std::vector<int>> pos2(ALPHABET_SIZE);
    getPos(pos2);
    std::string res;
    const int UNDEF = -1;
    int last1 = UNDEF;
    int last2 = UNDEF;
    for (int i = ALPHABET_SIZE - 1; i >= 0; i--) {
        while (!pos1[i].empty() && pos1[i].back() <= last1) {
            pos1[i].pop_back();
        }
        if (pos1[i].empty()) {
            continue;
        }
        while (!pos2[i].empty() && pos2[i].back() <= last2) {
            pos2[i].pop_back();
        }
        if (!pos2[i].empty()) {
            last1 = pos1[i].back();
            last2 = pos2[i].back();
            res += 'a' + i;
            i++;
        }
    }
    printf("%s", res.c_str());
    return 0;
}