#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(nV^3)
// Space complexity: O(nV^2)

enum State {
	NOT_CONNECTED, CONNECTED, IN_CYCLE
};

struct Edge {

	State s;

	int toV;

	int weight;

	int id;

	Edge()
		: s(State::NOT_CONNECTED)
	{}

	Edge(State s, int toV, int weight, int id)
		: s(s)
		, toV(toV)
		, weight(weight)
		, id(id)
	{}
};

int main() {
	int nV, nE, nC;
	scanf("%d %d %d", &nV, &nE, &nC);
	std::vector<std::vector<Edge>> edges(nV, std::vector<Edge>(nV));
	for (int e = 1; e <= nE; e++) {
		int from, to, weight;
		scanf("%d %d %d", &from, &to, &weight);
		if (edges[from - 1][to - 1].s == State::NOT_CONNECTED ||
			edges[from - 1][to - 1].weight < weight
		) {
			edges[from - 1][to - 1] = {State::CONNECTED, to - 1, weight, e};
		}
	}
	for (int cur = 0; cur < nV; cur++) {
		for (int from = 0; from < nV; from++) {
			for (int to = 0; to < nV; to++) {
				if (edges[from][cur].s == State::CONNECTED && 
					edges[cur][to].s == State::CONNECTED &&
					(edges[from][to].s == State::NOT_CONNECTED || 
					edges[from][to].weight < edges[from][cur].weight + edges[cur][to].weight)
				) {
					edges[from][to] = {State::CONNECTED, 
									edges[from][cur].toV, 
									edges[from][cur].weight + edges[cur][to].weight, 
									edges[from][cur].id};
				}
			}
		}
	}
	for (int from = 0; from < nV; from++) {
		for (int to = 0; to < nV; to++) {
			for (int cur = 0; cur < nV; cur++) {
				if (edges[from][cur].s != State::NOT_CONNECTED && 
					edges[cur][to].s != State::NOT_CONNECTED &&
					edges[cur][cur].weight > 0
				) {
					edges[from][to].s = State::IN_CYCLE;
				}
			}
		}
	}
	std::vector<int> list(nC);
	for (int i = 0; i < nC; i++) {
		scanf("%d", &list[i]);
		list[i]--;
	}
	int count = 0;
	for (int i = 1; i < nC; i++) {
		if (edges[list[i - 1]][list[i]].s == State::IN_CYCLE) {
			printf("infinitely kind");
			return 0;
		}
		int cur = list[i - 1];
		while (cur != list[i]) {
			count++;
			if (edges[cur][cur].s == State::IN_CYCLE) {
				printf("infinitely kind");
				return 0;
			}
			cur = edges[cur][edges[cur][list[i]].toV].toV;
		}
		if (edges[cur][cur].s == State::IN_CYCLE) {
			printf("infinitely kind");
			return 0;
		}
	}
	printf("%d\n", count);
	for (int i = 1; i < nC; i++) {
		int cur = list[i - 1];
		while (cur != list[i]) {
			printf("%d ", edges[cur][edges[cur][list[i]].toV].id);
			cur = edges[cur][edges[cur][list[i]].toV].toV;
		}
	}
	return 0;
}