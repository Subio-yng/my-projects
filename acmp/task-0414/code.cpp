#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV)
// Space complexity: O(nV)
 
int main() {
    int nV;
    scanf("%d", &nV);
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    std::vector<int> edges(nV);
    for (int i = 1; i < nV; i++) {
        scanf("%d", &edges[i]);
    }
    while (v1 != v2) {
        if (v1 > v2) {
            v1 = edges[v1 - 1];
        } else {
            v2 = edges[v2 - 1];
        }
    }
    printf("%d", v1);
    return 0;
}