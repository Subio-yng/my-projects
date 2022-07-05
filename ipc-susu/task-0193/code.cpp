#include <stdio.h>
#include <vector>

// Time complexity: O(nV * alpha(nV))
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

struct Date {

	int day;

	int month;

	int year;

	static Date read() {
		int d, m, y;
		scanf("%d/%d/%d", &d, &m, &y);
		return {d, m, y};
	}
};

struct Edge {

	int from;

	int to;

	Date date;

	static Edge read() {
		int f, t;
		scanf("%d %d", &f, &t);
		return {f - 1, t - 1, Date::read()};
	}
};

int main() {
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	DSU dsu(nV);
	int count = 0;
	for (int i = 0; i < nE; i++) {
		Edge curE = Edge::read();
		if (dsu.unionSets(curE.from, curE.to)) {
			count++;
		}
		if (count == nV - 1) {
			printf("%02d/%02d/%04d", curE.date.day, curE.date.month, curE.date.year);
			break;
		}
	}
	return 0;
}