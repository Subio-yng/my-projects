#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV^3)
// Space complexity: O(nV^2)

struct Edge {

	int from;

	int to;

	int weight;
};

int main() {
	const int UNDEF = 100000;
	const int INF = 1'000'000'000;
	int nV;
	scanf("%d", &nV);
	std::vector<Edge> edges;
	for (int from = 0; from < nV; from++) {
		for (int to = 0; to < nV; to++) {
			int weight;
			scanf("%d", &weight);
			if (weight != UNDEF) {
				edges.push_back({from, to, weight});
			}
		}
	}
	for (int curV = 0; curV < nV; curV++) {
		std::vector<int> dist(nV, INF);
		dist[curV] = 0;
		for (int cur = 1; cur < nV; cur++) {
			for (Edge nextE : edges) {
				if (dist[nextE.from] < INF) {
					dist[nextE.to] = std::min(dist[nextE.to], dist[nextE.from] + nextE.weight);
				}
			}
		}
		for (Edge nextE : edges) {
			if (dist[nextE.from] < INF && dist[nextE.to] > dist[nextE.from] + nextE.weight) {
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}