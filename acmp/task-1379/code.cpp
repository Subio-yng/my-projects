#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(maxF * nE)
// Space complexity: O(nE)

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
	int nV, nE, maxF, startV, endV;
	scanf("%d %d %d %d %d", &nV, &nE, &maxF, &startV, &endV);
	startV--;
	endV--;
	std::vector<Edge> edges(nE);
	for (int i = 0; i < nE; i++) {
		edges[i] = Edge::read();
	}
	const int UNDEF = -1;
	std::vector<std::vector<int>> dist(maxF + 1, std::vector<int>(nV, UNDEF));
	dist[0][startV] = 0;
	for (int i = 1; i <= maxF; i++) {
		for (Edge nextE : edges) {
			if (dist[i - 1][nextE.from] != UNDEF) {
				int newDist = dist[i - 1][nextE.from] + nextE.weight;
				if (dist[i][nextE.to] == UNDEF || dist[i][nextE.to] > newDist) {
					dist[i][nextE.to] = newDist;
				}
			}
		}
	}
	int minDist = UNDEF;
	for (int i = 0; i <= maxF; i++) {
		if (minDist == UNDEF || minDist > dist[i][endV]) {
			minDist = dist[i][endV];
		}
	}
	printf("%d", minDist);
	return 0;
}