#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(nV^2)
// Space complexity: O(nV^2)

void bfs(int curV,
		 int endV,
		 std::vector<int> &dist,
		 std::queue<int> &inProcess,
		 std::vector<bool> &visited, 
		 const std::vector<std::vector<bool>> &edges
) {
	dist[curV] = 0;
	inProcess.push(curV);
	visited[curV] = true;
	while (!inProcess.empty()) {
		int nextV = inProcess.front();
		inProcess.pop();
		for (int v = 0; v < (int) edges[nextV].size(); v++) {
			if (edges[nextV][v] && !visited[v]) {
				dist[v] = dist[nextV] + 1;
				inProcess.push(v);
				visited[v] = true;
			}
		}
	}
}

int main() {
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
	std::vector<bool> visited(nV, false);
	std::queue<int> inProcess;
	std::vector<int> dist(nV, -1);
	bfs(startV - 1, endV - 1, dist, inProcess, visited, edges);
	printf("%d", dist[endV - 1]);
	return 0;
}