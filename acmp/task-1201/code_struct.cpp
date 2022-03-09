#include <stdio.h>
#include <vector>
 
// Time complexity: O(n^2)
// Space complexity: O(n^2)
 
struct Graph {
 
    int from;
 
    int to;
};
 
int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<Graph> list;
    for (int i = 1; i <= nV; i++) {
        for (int j = 1; j <= nV; j++) {
            char val;
            scanf(" %c", &val);
            if (val == '1') {
                list.push_back({i, j});
            }
        }
    }
    printf("%d %d", nV, (int) list.size());
    for (int i = 0; i < (int) list.size(); i++) {
        printf("\n%d %d", list[i].from, list[i].to);
    }
    return 0;
}