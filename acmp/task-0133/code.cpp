#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(nE * log(nV))
// Space complexity: O(nV + nE)

struct Vertex {

	int id;

	int dist;

	bool operator <(const Vertex &a) const {
		if (dist == a.dist) {
			return id > a.id;
		}
		return dist > a.dist;
	}
};

int main() {
	int nV;
	scanf("%d", &nV);
	std::vector<int> weight(nV);
	for (int i = 0; i < nV; i++) {
		scanf("%d", &weight[i]);
	}
	int nE;
	scanf("%d", &nE);
	std::vector<std::vector<int>> edges(nV);
	for (int i = 0; i < nE; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		edges[from - 1].push_back(to - 1);
		edges[to - 1].push_back(from - 1);
	}
	const int UNDEF = -1;
	std::vector<int> dist(nV, UNDEF);
	std::priority_queue<Vertex> inProcess;
	std::vector<int> isFinal(nV, false);
	dist[0] = 0;
	inProcess.push({0, 0});
	while (!inProcess.empty()) {
		Vertex bestFrom = inProcess.top();
		inProcess.pop();
		if (isFinal[bestFrom.id]) {
			continue;
		}
		if (dist[bestFrom.id] == UNDEF) {
			break;
		}
		isFinal[bestFrom.id] = true;
		for (int to : edges[bestFrom.id]) {
			if (dist[to] == UNDEF || dist[to] > bestFrom.dist + weight[bestFrom.id]) {
				dist[to] = dist[bestFrom.id] + weight[bestFrom.id];
				inProcess.push({to, dist[to]});
			}
		}
	}
	printf("%d", dist[nV - 1]);
	return 0;
}