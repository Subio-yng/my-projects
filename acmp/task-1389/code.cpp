#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(sizeI * sizeJ * alpha(sizeI * sizeJ))
// Space complexity: O(sizeI * sizeJ)

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
            if (rank[b] > rank[a]) {
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

struct Edge {

    int i;

    int j;

    char d;
};

int main() {
    int sizeI, sizeJ;
    scanf("%d %d", &sizeI, &sizeJ);
    DSU dsu(sizeI * sizeJ);
    for (int v = 0; v < sizeI * sizeJ; v++) {
        char val;
        scanf(" %c", &val);
        if (val == '1' || val == '3') {
            dsu.unionSets(v, v + sizeJ);
        }
        if (val == '2' || val == '3') {
            dsu.unionSets(v, v + 1);
        }
    }
    int cost = 0;
    std::vector<Edge> ans;
    for (int i = 0; i < sizeI - 1; i++) {
        for (int j = 0; j < sizeJ; j++) {
            if (dsu.unionSets(i * sizeJ + j, (i + 1) * sizeJ + j)) {
                ans.push_back({i, j, '1'});
                cost++;
            }
        }
    }
    for (int i = 0; i < sizeI; i++) {
        for (int j = 0; j < sizeJ - 1; j++) {
            if (dsu.unionSets(i * sizeJ + j, i * sizeJ + j + 1)) {
                ans.push_back({i, j, '2'});
                cost += 2;
            }
        }
    }
    printf("%d %d", (int) ans.size(), cost);
    for (Edge next : ans) {
        printf("\n%d %d %c", next.i + 1, next.j + 1, next.d);
    }
    return 0;
}