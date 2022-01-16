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
};

int main() {
    Box n1 = Box::read();
    Box n2 = Box::read();
    Box n3 = Box::read();
    if (n1.height + n2.height <= n3.height &&
        (std::max(n1.len, n2.len) <= n3.len &&
         std::max(n1.width, n2.width) <= n3.width ||
         std::max(n1.width, n2.len) <= n3.len &&
         std::max(n1.len, n2.width) <= n3.width ||
         std::max(n1.len, n2.width) <= n3.len &&
         std::max(n1.width, n2.len) <= n3.width ||
         std::max(n1.width, n2.width) <= n3.len &&
         std::max(n1.len, n2.len) <= n3.width) ||
        std::max(n1.height, n2.height) <= n3.height &&
        (n1.len + n2.len <= n3.len &&
         std::max(n1.width, n2.width) <= n3.width ||
         n1.len + n2.width <= n3.len &&
         std::max(n1.width, n2.len) <= n3.width ||
         n1.width + n2.len <= n3.len &&
         std::max(n1.len, n2.width) <= n3.width ||
         n1.width + n2.width <= n3.len &&
         std::max(n1.len, n2.len) <= n3.width ||
         n1.len + n2.len <= n3.width &&
         std::max(n1.width, n2.width) <= n3.len ||
         n1.len + n2.width <= n3.width &&
         std::max(n1.width, n2.len) <= n3.len ||
         n1.width + n2.len <= n3.width &&
         std::max(n1.len, n2.width) <= n3.len ||
         n1.width + n2.width <= n3.width &&
         std::max(n1.len, n2.len) <= n3.len)
        ) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}