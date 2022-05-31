#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV^2 * nE)
// Space complexity: O(nV * nE)

struct Edge {

	int fromV;

	int fromT;

	int toV;

	int toT;
};

int main() {
	int nV, endV;
	scanf("%d %d", &nV, &endV);
	int nE;
	scanf("%d", &nE);
	std::vector<Edge> edges;
 	for (int i = 0; i < nE; i++) {
		int curE;
		scanf("%d", &curE);
		int prevV;
		int prevTime;
		scanf("%d %d", &prevV, &prevTime);
		for (int j = 1; j < curE; j++) {
			int toV, toTime;
			scanf("%d %d", &toV, &toTime);
			edges.push_back({prevV - 1, prevTime, toV - 1, toTime});
			prevV = toV;
			prevTime = toTime;
		}
	}
	const int INF = 1'000'000'000 + 1;
	std::vector<int> minTime(nV, INF);
	minTime[0] = 0;
	bool hasChanged = true;
	while (hasChanged) {
		hasChanged = false;
		for (Edge nextE : edges) {
			if (minTime[nextE.fromV] <= nextE.fromT &&
				minTime[nextE.toV] > nextE.toT
			) {
				minTime[nextE.toV] = nextE.toT;
				hasChanged = true;
			}
		}
	}
	if (minTime[endV - 1] == INF) {
		printf("-1");
	} else {
		printf("%d", minTime[endV - 1]);
	}
	return 0;
}