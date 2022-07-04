#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

// Time complexity: O(nV * nE * alpha(nV))
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
	std::vector<bool> used(nE, false);
	for (int i = 0; i < nE; i++) {
		if (dsu.unionSets(edges[i].from, edges[i].to)) {
			used[i] = true;
		}
	}
	int sum = INT_MAX;
	for (int i = 0; i < nV - 1; i++) {
		dsu = DSU(nV);
		int count = i;
		int countE = 0;
		int curSum = 0;
		for (int j = 0; j < nE; j++) {
			if (used[j] && count == 0) {
				count--;
				continue;
			}
			if (dsu.unionSets(edges[j].from, edges[j].to)) {
				if (used[j]) {
					count--;
				}
				countE++;
				curSum += edges[j].weight;
			}
		}
		if (sum > curSum && countE == nV - 1) {
			sum = curSum;
		}
	}
	printf("%d", sum);
	return 0;
}