#include <bits/stdc++.h>

// Time complexity: O((n + nQ) * log(n))
// Space complexity: O(n)

unsigned int getIP() {
    static unsigned int v1, v2, v3, v4;
    scanf("%u.%u.%u.%u", &v1, &v2, &v3, &v4);
    return (v1 << 24) | (v2 << 16) | (v3 << 8) | v4;
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<unsigned int> mask(n, 0);
    for (int i = 0; i < n; i++) {
        mask[i] = getIP();
    }
    std::sort(mask.begin(), mask.end());
    int nQ;
    scanf("%d", &nQ);
    for (int i = 0; i < nQ; i++) {
        unsigned int ip1 = getIP();
        unsigned int ip2 = getIP();
        int left = -1;
        int right = n;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if ((ip1 & mask[mid]) == (ip2 & mask[mid])) {
                left = mid;
            } else {
                right = mid;
            }
        }
        printf("%d\n", right);
    }
    return 0;
}