#include <stdio.h>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

struct Box {

    int len;

    int width;

    int height;

    static Box read() {
        int l, w, h;
        scanf("%d %d %d", &l, &w, &h);
        return {l, w, h};
    }

    void turn() {
        std::swap(this->len, this->width);
    }
};

bool checkHeight(Box n1, Box n2, Box n3) {
    return n1.height + n2.height <= n3.height &&
           std::max(n1.len, n2.len) <= n3.len &&
           std::max(n1.width, n2.width) <= n3.width;
}

bool checkLen(Box n1, Box n2, Box n3) {
    return std::max(n1.height, n2.height) <= n3.height &&
           n1.len + n2.len <= n3.len &&
           std::max(n1.width, n2.width) <= n3.width;
}

bool checkWidth(Box n1, Box n2, Box n3) {
    return std::max(n1.height, n2.height) <= n3.height &&
           std::max(n1.len, n2.len) <= n3.len &&
           n1.width + n2.width <= n3.width;
}

bool isFit(Box n1, Box n2, Box n3) {
    for (int countTurn = 0; countTurn <= 3; countTurn++) {
        if (checkHeight(n1, n2, n3) ||
            checkLen(n1, n2, n3) ||
            checkWidth(n1, n2, n3)
        ) {
            return true;
        }
        n1.turn();
        if (countTurn % 2 == 1) {
            n2.turn();
        }
    }
    return false;
}

int main() {
    Box n1 = Box::read();
    Box n2 = Box::read();
    Box n3 = Box::read();
    if (isFit(n1, n2, n3)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}