#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(log(range) * nE * log(nV))
// Space complexity: O(nV + nE)

struct Edge {

	int to;

	int minutes;

	int maxWeight;
};

struct Vertex {

	int id;

	int minutes;

	bool operator <(const Vertex &a) const {
		if (minutes == a.minutes) {
			return id > a.id;
		}
		return minutes > a.minutes;
	}
};

const int MAX_MINUTES = 1440;
const int INF = 1'000'000'000 + 5000;

bool canReach(int nV, int nE, int curWeight, const std::vector<std::vector<Edge>> &edges) {
	std::vector<int> dist(nV, INF);
	std::priority_queue<Vertex> inProcess;
	std::vector<bool> isFinal(nV, false);
	dist[0] = 0;
	inProcess.push({0, dist[0]});
	while (!inProcess.empty()) {
		Vertex bestFrom = inProcess.top();
		inProcess.pop();
		if (isFinal[bestFrom.id]) {
			continue;
		}
		if (dist[bestFrom.id] == INF) {
			break;
		}
		isFinal[bestFrom.id] = true;
		for (Edge nextE : edges[bestFrom.id]) {
			int newMinutes = bestFrom.minutes + nextE.minutes;
			if (curWeight <= nextE.maxWeight && 
				newMinutes <= MAX_MINUTES &&
				dist[nextE.to] > newMinutes
			) {
				dist[nextE.to] = newMinutes;
				inProcess.push({nextE.to, dist[nextE.to]});
			}
		}
	}
	return dist[nV - 1] != INF;
}

int main() {
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	std::vector<std::vector<Edge>> edges(nV);
	const int WEIGHT_TRUCK = 3'000'000;
	for (int i = 0; i < nE; i++) {
		int from, to, minutes, maxW;
		scanf("%d %d %d %d", &from, &to, &minutes, &maxW);
		maxW -= WEIGHT_TRUCK;
		if (maxW < 0) {
			continue;
		}
		from--;
		to--;
		edges[from].push_back({to, minutes, maxW});
		edges[to].push_back({from, minutes, maxW});
	}
	const int MAX_WEIGHT = 1'000'000'000;
	int rightWeight = MAX_WEIGHT + 1;
	int leftWeight = -1;
	while (leftWeight + 1 < rightWeight) {
		int midWeight = (leftWeight + rightWeight) / 2;
		if (canReach(nV, nE, midWeight, edges)) {
			leftWeight = midWeight;
		} else {
			rightWeight = midWeight;
		}
	}
	printf("%d", leftWeight / 100);
	return 0;
}