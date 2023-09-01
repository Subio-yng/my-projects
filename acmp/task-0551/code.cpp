#include <bits/stdc++.h>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    int rFence, rTree, hTree, dist;
    scanf("%d %d %d %d", &rFence, &rTree, &hTree, &dist);
    hTree -= dist - rTree;
    if (rFence * rFence - rTree * rTree >= hTree * hTree) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
