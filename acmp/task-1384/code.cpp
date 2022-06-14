#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(nE * log(nV))
// Space complexity: O(nV + nE)

enum State {
	UNMARKED, LEFT, RIGHT
};

struct Edge {

	int to;

	int weight;
};

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
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	const int INF = 1'000'000'000;
	std::vector<State> marks(nV);
	std::priority_queue<Vertex> inProcess;
	std::vector<int> dist(nV, INF);
	std::vector<int> startV(nV);
	for (int i = 0; i < nV; i++) {
		char val;
		scanf(" %c", &val);
		if (val == '0') {
			marks[i] = State::UNMARKED;
		} else if (val == '1') {
			marks[i] = State::LEFT;
			dist[i] = 0;
			startV[i] = i;
			inProcess.push({i, dist[i]});
		} else if (val == '2') {
			marks[i] = State::RIGHT;
		} else {
			throw 1;
		}
	}
	std::vector<std::vector<Edge>> edges(nV);
	for (int i = 0; i < nE; i++) {
		int from, to, weight;
		scanf("%d %d %d", &from, &to, &weight);
		from--;
		to--;
		edges[from].push_back({to, weight});
		edges[to].push_back({from, weight});
	}
	int bestFrom = INF;
	int bestTo = INF;
	int bestWeight = INF;
	std::vector<bool> isFinal(nV, false);
	while (!inProcess.empty()) {
		Vertex curFrom = inProcess.top();
		inProcess.pop();
		if (isFinal[curFrom.id]) {
			continue;
		}
		if (dist[curFrom.id] == INF) {
			break;
		}
		if (marks[curFrom.id] == State::RIGHT &&
			curFrom.dist < bestWeight
		) {
			bestFrom = startV[curFrom.id];
			bestTo = curFrom.id;
			bestWeight = curFrom.dist;
		}
		isFinal[curFrom.id] = true;
		for (Edge nextE : edges[curFrom.id]) {
			int newDist = curFrom.dist + nextE.weight;
			if (dist[nextE.to] > newDist) {
				dist[nextE.to] = newDist;
				startV[nextE.to] = startV[curFrom.id];
				inProcess.push({nextE.to, newDist});
			}
		}
	}
	if (bestWeight == INF) {
		printf("-1");
	} else {
		printf("%d %d %d", bestFrom + 1, bestTo + 1, bestWeight);
	}
	return 0;
}