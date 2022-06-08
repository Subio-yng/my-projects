#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(nE * log(nV))
// Space complexity: O(nE)

struct Edge {

	int fromT;

	int to;

	int toT;

	static Edge read() {
		int fT, t, tT;
		scanf("%d %d %d", &fT, &t, &tT);
		return {fT, t - 1, tT};
	}
};

struct Vertex {

	int id;

	int time;

	bool operator <(const Vertex &a) const {
		if (time == a.time) {
			return id > a.id;
		}
		return time > a.time;
	}
};

int main() {
	int nV;
	scanf("%d", &nV);
	int startV, endV;
	scanf("%d %d", &startV, &endV);
	startV--;
	endV--;
	int nE;
	scanf("%d", &nE);
	std::vector<std::vector<Edge>> edges(nV);
	for (int i = 0; i < nE; i++) {
		int from;
		scanf("%d", &from);
		edges[from - 1].push_back(Edge::read());
	}
	const int UNDEF = -1;
	std::vector<int> dist(nV, UNDEF);
	std::priority_queue<Vertex> inProcess;
	std::vector<bool> isFinal(nV, false);
	inProcess.push({startV, 0});
	dist[startV] = 0;
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
		for (Edge nextE : edges[bestFrom.id]) {
			if (bestFrom.time <= nextE.fromT && 
				(dist[nextE.to] == UNDEF || dist[nextE.to] > nextE.toT)
			) {
				dist[nextE.to] = nextE.toT;
				inProcess.push({nextE.to, nextE.toT});
			}
		}
	}
	printf("%d", dist[endV]);
	return 0;
}