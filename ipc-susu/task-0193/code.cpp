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

struct Date {

	int day;

	int month;

	int year;

	static Date read() {
		int d, m, y;
		scanf("%d/%d/%d", &d, &m, &y);
		return {d, m, y};
	}

	bool operator ==(const Date &a) const {
		return day == a.day && month == a.month && year == a.year;
	}

	bool operator <(const Date &a) const {
		if (year == a.year) {
			if (month == a.month) {
				return day < a.day;
			}
			return month < a.month;
		}
		return year < a.year;
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
	std::vector<Edge> edges(nE);
	for (int i = 0; i < nE; i++) {
		edges[i] = Edge::read();
	}
	std::sort(edges.begin(), edges.end(), [](const Edge &left, const Edge &right) {
		if (left.date == right.date) {
			if (left.from == right.from) {
				return left.to < right.to;
			}
			return left.from < right.from;
		}
		return left.date < right.date;
	});
	DSU dsu(nV);
	int count = 0;
	for (Edge nextE : edges) {
		if (dsu.unionSets(nextE.from, nextE.to)) {
			count++;
		}
		if (count == nV - 1) {
			printf("%02d/%02d/%04d", nextE.date.day, nextE.date.month, nextE.date.year);
			break;
		}
	}
	return 0;
}