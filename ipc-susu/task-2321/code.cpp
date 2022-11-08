#include <bits/stdc++.h>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
    const int SIZE_SNOWFLAKE = 6;
    int n;
    scanf("%d", &n);
    std::set<std::vector<int>> snowflake;
    std::vector<int> cur(SIZE_SNOWFLAKE, 0);
    std::vector<int> revCur(SIZE_SNOWFLAKE, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < SIZE_SNOWFLAKE; j++) {
            scanf("%d", &cur[j]);
            revCur[SIZE_SNOWFLAKE - j - 1] = cur[j];
        }
        bool find = false;
        for (int j = 0; j < SIZE_SNOWFLAKE; j++) {
            if (snowflake.find(cur) != snowflake.end() ||
                snowflake.find(revCur) != snowflake.end()
            ) {
                find = true;
                break;
            }
            cur.insert(cur.begin(), cur.back());
            cur.pop_back();
            revCur.insert(revCur.begin(), revCur.back());
            revCur.pop_back();
        }
        if (!find) {
            snowflake.insert(cur);
        }
    }
    printf("%d", (int) snowflake.size());
    return 0;
}