#include <stdio.h>
#include <vector>

// Time complexity: O(a(nV))
// Space complexity: O(nV)

const int UNDEF = -1;

struct DSU {

	std::vector<int> parent;

	std::vector<int> rank;

	void make_set(int v) {
		parent[v] = v;
		rank[v] = 0;
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

	DSU(int nV) {
		parent.resize(nV, UNDEF);
		rank.resize(nV, UNDEF);
	}
};

void printEdges(const DSU &a, int n) {
	if (a.parent[n] != n) {
		printEdges(a, a.parent[n]);
		printf("%d %d", a.parent[n] + 1, n + 1);
	}
}

int main() {
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	DSU arr(nV);
	for (int i = 0; i < nE; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		from--;
		to--;
		if (arr.parent[from] == UNDEF) {
			arr.make_set(from);
		}
		if (arr.parent[to] == UNDEF) {
			arr.make_set(to);
		}
		if (arr.union_sets(from, to)) {
			printf("%d %d\n", from + 1, to + 1);
		}
	}
	return 0;
}