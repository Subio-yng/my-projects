#include <bits/stdc++.h>

// Time complexity: O(n^2)
// Space complexity: O(n)

struct Mass {

    __int128 realVal;

    int val;

    std::string type;

    static Mass read() {
        int val;
        char type[1 + 2];
        scanf("%d %s", &val, &type);
        __int128 realVal = val;
        int cur = 0;
        if (type[cur] == 'm') {
            cur++;
        } else if (type[cur] == 'k') {
            realVal *= 1'000'000;
            cur++;
        } else if (type[cur] == 'M') {
            realVal *= 1'000'000'000;
            cur++;
        } else if (type[cur] == 'G') {
            realVal *= 1'000'000'000'000LL;
            cur++;
        }
        if (cur == 0) {
            realVal *= 1'000;
        }
        if (type[cur] == 'p') {
            realVal *= 16380;
        } else if (type[cur] == 't') {
            realVal *= 1'000'000;
        }
        return {realVal, val, type};
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Mass> list(n);
    for (int i = 0; i < n; i++) {
        list[i] = Mass::read();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (list[j].realVal < list[j - 1].realVal) {
                std::swap(list[j], list[j - 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", list[i].val, list[i].type.c_str());
    }
    return 0;
}