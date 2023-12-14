#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
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
    std::stable_sort(list.begin(), list.end(), [](const Mass &left, const Mass &right) {
        return left.realVal < right.realVal;
    });
    for (const Mass &next : list) {
        printf("%d %s\n", next.val, next.type.c_str());
    }
    return 0;
}