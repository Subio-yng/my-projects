#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV^3)
// Space complexity: O(nV^2)

int main() {
	const int INF = 1'000'000'000;
	const int UNDEF = 100000;
	int nV;
	scanf("%d", &nV);
	std::vector<std::vector<int>> edges(nV, std::vector<int>(nV));
	for (int from = 0; from < nV; from++) {
		for (int to = 0; to < nV; to++) {
			scanf("%d", &edges[from][to]);
			if (edges[from][to] == UNDEF) {
				edges[from][to] = INF;
			}
		}
	}
	for (int cur = 0; cur < nV; cur++) {
		for (int from = 0; from < nV; from++) {
			for (int to = 0; to < nV; to++) {
				if (edges[from][cur] < INF && edges[cur][to] < INF) {
					edges[from][to] = std::min(edges[from][to], edges[from][cur] + edges[cur][to]);
				}
			}
		}
	}
	for (int cur = 0; cur < nV; cur++) {
		for (int from = 0; from < nV; from++) {
			for (int to = 0; to < nV; to++) {
				if (edges[from][cur] < INF && edges[cur][to] < INF && 
					edges[from][to] > edges[from][cur] + edges[cur][to]
				) {
					printf("YES");
					return 0;
				}
			}
		}
	}
	printf("NO");
	return 0;
}