#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV^2)
// Space complexity: O(nV^2)

int main() {
	int nV;
	int startV, endV;
	scanf("%d %d %d", &nV, &startV, &endV);
	startV--;
	endV--;
	const int UNDEF = -1;
	std::vector<std::vector<int>> edges(nV, std::vector<int>(nV));
	for (int from = 0; from < nV; from++) {
		for (int to = 0; to < nV; to++) {
			scanf("%d", &edges[from][to]);
		}
	}
	const int INF = 1'000'000;
	std::vector<int> dist(nV, INF);
	std::vector<int> visited(nV, false);
	dist[startV] = 0;
	for (int i = 0; i < nV; i++) {
		int bestFrom = UNDEF;
		for (int from = 0; from < nV; from++) {
			if (!visited[from] && (bestFrom == UNDEF || dist[from] < dist[bestFrom])) {
				bestFrom = from;
			}
		}
		if (bestFrom == INF) {
			break;
		}
		visited[bestFrom] = true;
		for (int to = 0; to < nV; to++) {
			if (edges[bestFrom][to] != UNDEF) {
				dist[to] = std::min(dist[to], dist[bestFrom] + edges[bestFrom][to]);
			}
		}
	}
	if (dist[endV] == INF) {
		printf("%d", UNDEF);
	} else {
		printf("%d", dist[endV]);
	}
	return 0;
}