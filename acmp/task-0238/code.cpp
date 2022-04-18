#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

const int UNDEF = -1;

struct Coord {

	int i;

	int j;

	static Coord read() {
		int i, j;
		scanf("%d %d", &i, &j);
		return {i - 1, j - 1};
	}

	bool operator <(const Coord &a) const {
		if (i == a.i) {
			return j < a.j;
		}
		return i < a.i;
	}
};

void bfs(Coord start, 
		 int sizeI, 
		 int sizeJ, 
		 std::map<Coord, Coord> &tunnels, 
		 std::vector<std::vector<int>> &dist,
		 const std::vector<std::vector<bool>> &state
) {
	dist[start.i][start.j] = 1;
	std::queue<Coord> inProcess;
	inProcess.push(start);
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		inProcess.pop();
		if (tunnels.find(cur) != tunnels.end()) {
			Coord curTunnel = tunnels[cur];
			if (dist[curTunnel.i][curTunnel.j] == UNDEF) {
				dist[curTunnel.i][curTunnel.j] = dist[cur.i][cur.j] + 1;
				inProcess.push(curTunnel);
			}
		}
		for (int di = -1; di <= 1; di++) {
			for (int dj = -1; dj <= 1; dj++) {
				if (di * di + dj * dj != 1) {
					continue;
				}
				int newI = cur.i + di;
				int newJ = cur.j + dj;
				if (0 <= newI && newI < sizeI &&
					0 <= newJ && newJ < sizeJ &&
					state[newI][newJ] &&
					dist[newI][newJ] == UNDEF
				) {
					dist[newI][newJ] = dist[cur.i][cur.j] + 1;
					inProcess.push({newI, newJ});
				}
			}
		}
	}
}

int main() {
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	Coord start = Coord::read();
	std::vector<std::vector<bool>> state(sizeI, std::vector<bool>(sizeJ, true));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			char val;
			scanf(" %c", &val);
			if (val == '1') {
				state[i][j] = false;
			}
		}
	}
	int nT;
	scanf("%d", &nT);
	std::map<Coord, Coord> tunnels;
	for (int i = 0; i < nT; i++) {
		Coord from = Coord::read();
		Coord to = Coord::read();
		tunnels[from] = to;
	}
	std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
	bfs(start, sizeI, sizeJ, tunnels, dist, state);
	int minWay = UNDEF;
	int nExit;
	scanf("%d", &nExit);
	for (int i = 0; i < nExit; i++) {
		Coord exit = Coord::read();
		if (dist[exit.i][exit.j] != UNDEF && (minWay == UNDEF || minWay > dist[exit.i][exit.j])) {
			minWay = dist[exit.i][exit.j];
		}
	}
	if (minWay == UNDEF) {
		printf("Impossible");
	} else {
		printf("%d", minWay);
	}
	return 0;
}