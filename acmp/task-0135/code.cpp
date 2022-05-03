#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV^3)
// Space complexity: O(nV^2)

int main() {
	int nV;
	scanf("%d", &nV);
	std::vector<std::vector<int>> edges(nV, std::vector<int>(nV));
	for (int from = 0; from < nV; from++) {
		for (int to = 0; to < nV; to++) {
			scanf("%d", &edges[from][to]);
		}
	}
	for (int cur = 0; cur < nV; cur++) {
		for (int from = 0; from < nV; from++) {
			for (int to = 0; to < nV; to++) {
				edges[from][to] = std::min(edges[from][to], edges[from][cur] + edges[cur][to]);
			}
		}
	}
	for (int from = 0; from < nV; from++) {
		for (int to = 0; to < nV; to++) {
			printf("%d ", edges[from][to]);
		}
		printf("\n");
	}
	return 0;
}