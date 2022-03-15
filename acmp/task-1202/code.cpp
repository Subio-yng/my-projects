#include <stdio.h>
#include <vector>
#include <set>
 
// Time complexity: O(nV + nE * log(nE))
// Space complexity: O(nV + nE)
 
int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<std::set<int>> edges(nV);
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from - 1].insert(to);
    }
    printf("%d", nV);
    for (int i = 0; i < nV; i++) {
        printf("\n%d", (int) edges[i].size());
        for (auto e : edges[i]) {
            printf(" %d", e);
        }
    }
    return 0;
}0