#include <stdio.h>
#include <vector>

// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)

struct DSU {

	std::vector<int> parent;

	std::vector<int> rank;

	DSU(int nV) {
		parent.resize(nV);
		rank.resize(nV);
		for (int i = 0; i < nV; i++) {
			parent[i] = i;
			rank[i] = 1;
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
			rank[a] += rank[b];
		}
		return a != b;
	}
};

void dfs(int curV, std::vector<bool> &visited, const std::vector<std::vector<int>> &edges) {
	visited[curV] = true;
	for (int nextV : edges[curV]) {
		if (!visited[nextV]) {
			dfs(nextV, visited, edges);
		}
	}
	printf("%d\n", curV + 1);
}

int main() {
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	DSU dsu(nV);
	std::vector<std::vector<int>> edges(nV);
	for (int i = 0; i < nE; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		from--;
		to--;
		if (dsu.unionSets(from, to)) {
			edges[from].push_back(to);
			edges[to].push_back(from);
		}
	}
	std::vector<bool> visited(nV, false);
	dfs(dsu.getRoot(0), visited, edges);
	return 0;
}