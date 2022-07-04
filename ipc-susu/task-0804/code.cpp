#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV^2 * log(nV))
// Space complexity: O(nV^2)

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

struct Coord {

    int x;

    int y;

    static Coord read() {
        int x, y;
        scanf("%d %d", &x, &y);
        return {x, y};
    }

    int getDistTo(const Coord &a) const {
        int dx = x - a.x;
        int dy = y - a.y;
        return dx * dx + dy * dy;
    }
};

struct Edge {

    int from;

    int to;

    int weight;
};

int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<Coord> field(nV);
    for (int i = 0; i < nV; i++) {
        field[i] = Coord::read();
    }
    int nE;
    scanf("%d", &nE);
    DSU dsu(nV);
    for (int i = 0; i < nE; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        dsu.unionSets(from - 1, to - 1);
    }
    std::vector<Edge> edges;
    for (int from = 0; from < nV - 1; from++) {
        for (int to = from + 1; to < nV; to++) {
            edges.push_back({from, to, field[from].getDistTo(field[to])});
        }
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
    for (Edge nextE : edges) {
        if (dsu.unionSets(nextE.from, nextE.to)) {
            printf("%d %d\n", nextE.from + 1, nextE.to + 1);
        }
    }
	return 0;
}