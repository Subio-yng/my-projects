#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

const int N_BUCKETS = 3;

struct Buckets {

	int c1;

	int c2;

	int c3;

	bool operator <(const Buckets &a) const {
		if (c1 == a.c1) {
			if (c2 == a.c2) {
				return c3 < a.c3;
			}
			return c2 < a.c2;
		}
		return c1 < a.c1;
	}

	int &getCap(int i) {
		if (i == 0) {
			return c1;
		} else if (i == 1) {
			return c2;
		} else if (i == 2) {
			return c3;
		} else {
			throw 1;
		}
	}
};

void bfs(const std::vector<int> &cap, int end) {
	std::map<Buckets, int> move;
	std::queue<Buckets> inProcess;
	inProcess.push({cap[0], 0, 0});
	move[{cap[0], 0, 0}] = 0;
	while (!inProcess.empty()) {
		Buckets cur = inProcess.front();
		if (cur.c1 == end) {
			printf("%d", move[cur]);
			return;
		}
		inProcess.pop();
		for (int from = 0; from < N_BUCKETS; from++) {
			for (int to = 0; to < N_BUCKETS; to++) {
				if (from == to) {
					continue;
				}
				Buckets next = cur;
				next.getCap(to) = std::min(next.getCap(from) + next.getCap(to), cap[to]);
				next.getCap(from) = std::max(0, cur.getCap(from) + cur.getCap(to) - cap[to]);
				if (move.find(next) == move.end()) {
					move[next] = move[cur] + 1;
					inProcess.push(next);
				}
			}
		}
	}
	printf("IMPOSSIBLE");
}

int main() {
	std::vector<int> capacity(N_BUCKETS);
	for (int i = 0; i < N_BUCKETS; i++) {
		scanf("%d", &capacity[i]);
	}
	int end;
	scanf("%d", &end);
	bfs(capacity, end);
	return 0;
}