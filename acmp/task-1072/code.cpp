#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV)
// Space complexity: O(nV^2)
 
int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<std::vector<int>> edges(nV);
    for (int i = 0; i < nV - 1; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        edges[from - 1].push_back(to - 1);
        edges[to - 1].push_back(from - 1);
    }
    int count = 0;
    for (int curV = 0; curV < nV; curV++) {
        if ((int) edges[curV].size() > 1) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}