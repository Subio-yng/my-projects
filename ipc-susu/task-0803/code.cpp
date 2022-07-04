#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nE * log(nE))
// Space complexity: O(nE)

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

struct Edge {

    int from;

    int to;

    int weight;

    static Edge read() {
        int f, t, w;
        scanf("%d %d %d", &f, &t, &w);
        return {f - 1, t - 1, w};
    }
};

int main() {
    int nV, nE;
    scanf("%d %d", &nV, &nE);
    std::vector<Edge> edges(nE);
    for (int i = 0; i < nE; i++) {
        edges[i] = Edge::read();
    }
    std::sort(edges.begin(), edges.end(), [](const Edge &left, const Edge &right) {
        if (left.weight == right.weight) {
            if (left.from == right.from) {
                return left.to < right.to;
            }
            return left.from < right.from;
        }
        return left.weight < right.weight;
    });
    DSU dsu(nV);
    std::vector<bool> hubs(nE, false);
    int maxWeight = 0;
    int count = 0;
    for (int i = 0; i < nE; i++) {
        if (dsu.unionSets(edges[i].from, edges[i].to)) {
            maxWeight = edges[i].weight;
            hubs[i] = true;
            count++;
        }
    }
    printf("%d\n", maxWeight);
    printf("%d", count);
    for (int i = 0; i < nE; i++) {
        if (hubs[i]) {
            printf("\n%d %d", edges[i].from + 1, edges[i].to + 1);
        }
    }
    return 0;
}