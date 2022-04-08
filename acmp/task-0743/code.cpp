#include <stdio.h>
#include <queue>
#include <unordered_map>

// Time complexity: O(nV + nE)
// Space complexity: O(nV + nE)

const int UNDEF = -1;

void bfs(const std::string &startV,
		const std::string &endV,
	    std::unordered_map<std::string, int> &dist,
		std::unordered_map<std::string, std::vector<std::string>> &edges
) {
	std::queue<std::string> inProcess;
	inProcess.push(startV);
	dist[endV] = UNDEF;
	dist[startV] = 0;
	while (!inProcess.empty()) {
		std::string curV = inProcess.front();
		inProcess.pop();
		for (auto nextV : edges[curV]) {
			if (dist[nextV] == -1) {
				dist[nextV] = dist[curV] + 1;
				inProcess.push(nextV);
			}
		}
	}
}

int main() {
	int nE;
	scanf("%d", &nE);
	std::unordered_map<std::string, std::vector<std::string>> edges;
	std::unordered_map<std::string, int> dist;
	char buf[1 + 20];
	for (int i = 0; i < nE; i++) {
		scanf(" %s", &buf);
		std::string from(buf);
		scanf(" -> ");
		scanf(" %s", &buf);
		std::string to(buf);
		edges[from].push_back(to);
		dist[to] = UNDEF;
	}
	scanf(" %s", &buf);
	std::string startV(buf);
	scanf(" %s", &buf);
	std::string endV(buf);
	bfs(startV, endV, dist, edges);
	printf("%d", dist[endV]);
	return 0;
}