#include <stdio.h>
#include <vector>

// Time complexity: O(nV^2)
// Space complexity: O(nV)

int main() {
	const int INF = 1'000'000;
	int nV;
	scanf("%d", &nV);
	std::vector<int> dist(nV, INF);
	dist[0] = 0;
	bool hasChanges = true;
	while (hasChanges) {
		hasChanges = false;
		for (int from = 0; from < nV; from++) {
			for (int to = from + 1; to < nV; to++) {
				if (dist[from] < INF) {
					int weight = ((from + 1) * 179 + (to + 1) * 719) % 1000 - 500;
					if (dist[to] > dist[from] + weight) {
						dist[to] = dist[from] + weight;
						hasChanges = true;
					}
				}
			}
		}
	}
	printf("%d", dist[nV - 1]);
	return 0;
}