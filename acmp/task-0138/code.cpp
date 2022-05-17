#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV * nE)
// Space complexity: O(nE)

struct Edge {

	int from;

	int to;

	int weight;
};

int main() {
	const int INF = 30000;
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	std::vector<Edge> edges(nE);
	for (int i = 0; i < nE; i++) {
		int from, to, weight;
		scanf("%d %d %d", &from, &to, &weight);
		edges[i] = {from - 1, to - 1, weight};
	}
	std::vector<int> dist(nV, INF);
	dist[0] = 0;
	for (int cur = 0; cur < nV; cur++) {
		for (int e = 0; e < nE; e++) {
			if (dist[edges[e].from] < INF) {
				dist[edges[e].to] = std::min(dist[edges[e].to], dist[edges[e].from] + edges[e].weight);
			}
		}
	}
	for (int next : dist) {
		printf("%d ", next);
	}
	return 0;
}