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

int main() {
	int nV, nE, needE;
	scanf("%d %d %d", &nV, &nE, &needE);
	if (needE > nE) {
		printf("-1");
		return 0;
	}
	std::vector<Edge> edges(nE);
	for (int i = 0; i < nE; i++) {
		edges[i] = Edge::read();
	}
	std::sort(edges.begin(), edges.end(), [](const Edge &left, const Edge &right) {
		if (left.weight == right.weight) {
			if (left.from == right.from) {
				return left.to > right.to;
			}
			return left.from > right.from;
		}
		return left.weight > right.weight;
	});
	DSU dsu(nV);
	std::vector<bool> used(nE, false);
	int count = 0;
	long long sum = 0;
	for (int i = 0; i < nE; i++) {
		if (dsu.unionSets(edges[i].from, edges[i].to)) {
			sum += edges[i].weight;
			count++;
			used[i] = true;
		}
	}
	if (count != nV - 1) {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < nE; i++) {
		if (count >= needE) {
			break;
		}
		if (!used[i]) {
			sum += edges[i].weight;
			count++;
		}
	}
	printf("%lld", sum);
	return 0;
}