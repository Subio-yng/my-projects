#include <stdio.h>
#include <vector>

// Time complexity: O(nV^2)
// Space complexity: O(nV)

struct Coord {

	int left;

	int top;

	int right;

	int bottom;

	static Coord read() {
		int x1, y1, x2, y2, r;
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &r);
		if (x1 > x2) {
			std::swap(x1, x2);
		}
		if (y2 > y1) {
			std::swap(y1, y2);
		}
		return {x1 - r, y1 + r, x2 + r, y2 - r};
	}
};

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

bool check(Coord a, Coord b) {
	if (a.left > b.left) {
		std::swap(a, b);
	}
	return a.right >= b.left && (a.top >= b.top && a.bottom <= b.top || 
								a.top <= b.top && b.bottom <= a.top);
}

int main() {
	int nV;
	scanf("%d", &nV);
	std::vector<Coord> field(nV);
	for (int i = 0; i < nV; i++) {
		field[i] = Coord::read();
	}
	DSU dsu(nV);
	int count = nV;
	for (int i = 0; i < nV - 1; i++) {
		for (int j = i + 1; j < nV; j++) {
			if (check(field[i], field[j]) && dsu.unionSets(i, j)) {
				count--;
			}
		}
	}
	printf("%d", count);
	return 0;
}