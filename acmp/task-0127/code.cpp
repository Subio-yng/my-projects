#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(nV^2)
// Space complexity: O(nV^2)

void bfs(int startV,
		 int endV,
		 std::vector<int> &dist,
		 std::queue<int> &inProcess,
		 std::vector<bool> &visited, 
		 const std::vector<std::vector<bool>> &edges
) {
	dist[startV] = 0;
	inProcess.push(startV);
	visited[startV] = true;
	while (!inProcess.empty()) {
		int curV = inProcess.front();
		inProcess.pop();
		if (curV == endV) {
			return;
		}
		for (int nextV = 0; nextV < (int) edges[curV].size(); nextV++) {
			if (edges[curV][nextV] && !visited[nextV]) {
				dist[nextV] = dist[curV] + 1;
				inProcess.push(nextV);
				visited[nextV] = true;
			}
		}
	}
}

int main() {
	const int UNDEF = -1;
	int nV;
	scanf("%d", &nV);
	std::vector<std::vector<bool>> edges(nV, std::vector<bool>(nV, false));
	for (int i = 0; i < nV; i++) {
		for (int j = 0; j < nV; j++) {
			char val;
			scanf(" %c", &val);
			if (val == '1') {
				edges[i][j] = true;
			}
		}
	}
	int startV, endV;
	scanf("%d %d", &startV, &endV);
	startV--;
	endV--;
	std::vector<bool> visited(nV, false);
	std::queue<int> inProcess;
	std::vector<int> dist(nV, UNDEF);
	bfs(startV, endV, dist, inProcess, visited, edges);
	printf("%d", dist[endV]);
	return 0;
}