#include <stdio.h>
#include <vector>
 
// Time complexity: O(n^2)
// Space complexity: O(n^2)
 
struct Edge {
 
    int from;
 
    int to;
};
 
int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<Edge> edges;
    for (int i = 1; i <= nV; i++) {
        for (int j = 1; j <= nV; j++) {
            char val;
            scanf(" %c", &val);
            if (val == '1') {
                edges.push_back({i, j});
            }
        }
    }
    printf("%d %d", nV, (int) edges.size());
    for (Edge &e : edges) {
        printf("\n%d %d", e.from, e.to);
    }
    return 0;
}