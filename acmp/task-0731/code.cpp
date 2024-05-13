#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(n)

struct Cell {

    char type;

    int val;

    static Cell read() {
        char t;
        int v;
        scanf(" %c %d", &t, &v);
        return {t, v};
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Cell> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        a[i] = Cell::read();
        sum += a[i].val;
        a[i].val *= 1000;
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        a[i].val /= sum;
        cur += a[i].val / 10;
    }
    for (char curType : {'+', '-'}) {
        for (int i = 0; i < n; i++) {
            if (cur < 100 && a[i].type == curType && a[i].val % 10 != 0) {
                a[i].val += 10 - a[i].val % 10;
                cur++;
            }
        }
    }
    for (Cell next : a) {
        printf("%d\n", next.val / 10);
    }
    return 0;
}