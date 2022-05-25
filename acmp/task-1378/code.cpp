#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV * nE)
// Space complexity: O(nE)

struct Edge {

	int fromV;

	int fromT;

	int toV;

	int toT;

	static Edge read() {
		int fV, fT, tV, tT;
		scanf("%d %d %d %d", &fV, &fT, &tV, &tT);
		return {fV - 1, fT, tV - 1, tT};
	}
};

int main() {
	int nV;
	scanf("%d", &nV);
	int startV;
	int endV;
	scanf("%d %d", &startV, &endV);
	startV--;
	endV--;
	int nE;
	scanf("%d", &nE);
	std::vector<Edge> edges(nE);
	for (int i = 0; i < nE; i++) {
		edges[i] = Edge::read();
	}
	const int INF = 1'000'000'000 + 1;
	std::vector<int> dist(nV, INF);
	dist[startV] = 0;
	bool hasChanged = true;
	while (hasChanged) {
		hasChanged = false;
		for (Edge nextE : edges) {
			if (dist[nextE.fromV] < INF && 
				dist[nextE.fromV] <= nextE.fromT && 
				dist[nextE.toV] > nextE.toT
			) {
				dist[nextE.toV] = nextE.toT;
				hasChanged = true;
			}
		}
	}
	printf("%d", dist[endV]);
	return 0;
}