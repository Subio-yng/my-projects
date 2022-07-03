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

	int from;

	int to;

	int weight;

	static Edge read() {
		int f, t, w;
		scanf("%d %d %d", &f, &t, &w);
		return {f - 1, t - 1, w};
	}
};

void solve(int nV, int nE) {
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
	int sum = 0;
	for (Edge nextE : edges) {
		if (dsu.unionSets(nextE.from, nextE.to)) {
			sum += nextE.weight;
		}
	}
	printf("%d\n", sum);
}

int main() {
	while (true) {
		int nV;
		scanf("%d", &nV);
		if (nV == 0) {
			break;
		}
		int nE;
		scanf("%d", &nE);
		solve(nV, nE);
	}
	return 0;
}