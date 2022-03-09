#include <stdio.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

struct Graph {

    int in;

    int out;
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<Graph> list;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char val;
            scanf(" %c", &val);
            if (val == '1') {
                list.push_back({i, j});
            }
        }
    }
    printf("%d %d", n, (int) list.size());
    for (int i = 0; i < (int) list.size(); i++) {
        printf("\n%d %d", list[i].in, list[i].out);
    }
    return 0;
}