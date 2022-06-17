#include <stdio.h>
#include <vector>

// Time complexity: O(a(nV))
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

	int get(int n) {
		int leader = n;
		while (parent[leader] != leader) {
			leader = parent[leader];
		}
		while (parent[n] != n) {
			n = parent[n];
			parent[n] = leader;
		}
		return leader;
	}

	bool union_sets(int a, int b) {
		a = get(a);
		b = get(b);
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
		from--;
		to--;
		if (dsu.union_sets(from, to)) {
			printf("%d %d\n", from + 1, to + 1);
		}
	}
	return 0;
}