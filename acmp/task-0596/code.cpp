#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(n)

struct Base {

    std::string name;

    int i;

    int j;

    int r;

    static Base read() {
        static char buf[1 + 50];
        scanf(" %s", &buf);
        int i, j, r;
        scanf("%d %d %d", &i, &j, &r);
        return {buf, i, j, r};
    }

    bool inRange(int qI, int qJ) {
        int dI = i - qI;
        int dJ = j - qJ;
        return dI * dI + dJ * dJ <= r * r;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Base> a(n);
    std::unordered_map<std::string, int> cnt;
    for (int i = 0; i < n; i++) {
        a[i] = Base::read();
        cnt[a[i].name] = 0;
    }
    int qI, qJ;
    scanf("%d %d", &qI, &qJ);
    for (Base next : a) {
        if (next.inRange(qI, qJ)) {
            cnt[next.name]++;
        }
    }
    const int UNDEF = -1;
    printf("%d\n", (int) cnt.size());
    for (Base next : a) {
        auto cur = cnt.find(next.name);
        if (cur->second != UNDEF) {
            printf("%s %d\n", cur->first.c_str(), cur->second);
            cur->second = UNDEF;
        }
    }
    return 0;
}