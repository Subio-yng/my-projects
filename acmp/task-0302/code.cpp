#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

// Time complexity: O(nV^2 * log(range) * alpha(nV))
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

struct Coord {
	
	double x;

	double y;

	static Coord read() {
		double x, y;
		scanf("%lf %lf", &x, &y);
		return {x, y};
	}

	double getDistTo(const Coord &a) const {
		double dx = x - a.x;
		double dy = y - a.y;
		return sqrt(dx * dx + dy * dy);
	}
};

int main() {
	int nV;
	scanf("%d", &nV);
	std::vector<Coord> field(nV);
	for (int i = 0; i < nV; i++) {
		field[i] = Coord::read();
	}
	double rightDist = 0;
	for (int i = 0; i < nV - 1; i++) {
		for (int j = i + 1; j < nV; j++) {
			rightDist = std::max(rightDist, field[i].getDistTo(field[j]));
		}
	}
	double leftDist = 0;
	const double EPS = 0.01;
	while (leftDist + EPS < rightDist) {
		double midDist = (leftDist + rightDist) / 2.0;
		DSU dsu(nV);
		int count = 0;
		for (int i = 0; i < nV - 1; i++) {
			for (int j = i + 1; j < nV; j++) {
				if (field[i].getDistTo(field[j]) <= midDist && dsu.unionSets(i, j)) {
					count++;
				}
			}
		}
		if (count == nV - 1) {
			rightDist = midDist;
		} else {
			leftDist = midDist;
		}
	}
	printf("%.2f", rightDist);
	return 0;
}