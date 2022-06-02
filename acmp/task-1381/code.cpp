#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV^2)
// Space complexity: O(nV^2)

void printWay(const std::vector<int> &prev, int curV, int endV) {
	if (curV == endV) {
		printf("%d", curV + 1);
		return;
	}
	printWay(prev, prev[curV], endV);
	printf(" %d", curV + 1);
}

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
	std::vector<int> prev(nV);
	dist[startV] = 0;
	for (int i = 0; i < nV; i++) {
		int bestFrom = UNDEF;
		for (int from = 0; from < nV; from++) {
			if (!visited[from] && (bestFrom == UNDEF || dist[from] < dist[bestFrom])) {
				bestFrom = from;
			}
		}
		if (bestFrom == UNDEF) {
			break;
		}
		visited[bestFrom] = true;
		for (int to = 0; to < nV; to++) {
			if (edges[bestFrom][to] != UNDEF && dist[to] > dist[bestFrom] + edges[bestFrom][to]) {
				dist[to] = dist[bestFrom] + edges[bestFrom][to];
				prev[to] = bestFrom;
			}
		}
	}
	if (dist[endV] == INF) {
		printf("%d", UNDEF);
	} else {
		printWay(prev, endV, startV);
	}
	return 0;
}