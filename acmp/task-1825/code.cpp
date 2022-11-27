#include <bits/stdc++.h>

// Time complexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    char typeRead;
    scanf(" %c", &typeRead);
    std::vector<int> line(n);
    if (typeRead == '1') {
        for (int i = 0; i < n; i++) {
            scanf("%d", &line[i]);
        }
    } else {
        const int MOD = 1'000'000'000;
        int m, x, y, z;
        scanf("%d %d %d %d", &m, &x, &y, &z);
        for (int i = 0; i < n; i++) {
            if (i < m) {
                scanf("%d", &line[i]);
            } else {
                line[i] = (1LL * x * line[i - 2] % MOD + 1LL * y * line[i - 1] % MOD + z) % MOD + 1;
            }
        }
    }
    int maxId = 0;
    for (int i = 1; i < n; i++) {
        if (line[i] > line[maxId]) {
            maxId = i;
        }
    }
    int minJump = line[maxId];
    int idJump = maxId;
    int curJump = line[maxId];
    for (int i = 1; i < n; i++) {
        int curId = (maxId - i + n) % n;
        curJump = std::max(curJump - 1, line[curId]);
        if (curJump < minJump) {
            minJump = curJump;
            idJump = curId;
        }
    }
    printf("%d %d", minJump, idJump + 1);
    return 0;
}