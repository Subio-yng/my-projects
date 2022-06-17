#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV)
// Space complexity: O(nV)
 
struct DSU {
 
    std::vector<int> parent;
 
    std::vector<int> rank;
 
    DSU(int nV) {
        parent.resize(nV);
        rank.resize(nV);
        for (int i = 0; i < nV; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
 
    int getRoot(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = getRoot(parent[n]);
    }
 
    bool unionSets(int a, int b) {
        a = getRoot(a);
        b = getRoot(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                std::swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
        return a != b;
    }
};
 
int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    DSU dsu(nV);
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        if (dsu.unionSets(from - 1, to - 1)) {
            printf("%d %d\n", from, to);
        }
    }
    return 0;
}