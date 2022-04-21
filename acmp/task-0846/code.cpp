#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

const int UNDEF = -1;
const int N_HEROES = 4;

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

int bfs(Coord end,
		int move,
		int sizeI,
		int sizeJ,
		std::map<Coord, int> &start, 
		const std::vector<std::vector<bool>> &state
) {
	std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
	std::queue<Coord> inProcess;
	inProcess.push(end);
	dist[end.i][end.j] = 0;
	int sum = 0;
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		inProcess.pop();
		if (dist[cur.i][cur.j] > move) {
			continue;
		}
		sum += start[cur];
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
	return sum;
}

int main() {
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
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
	Coord end = Coord::read();
	if (!state[end.i][end.j]) {
		printf("0");
		return 0;
	}
	int move;
	scanf("%d", &move);
	std::map<Coord, int> start;
	for (int h = 0; h < N_HEROES; h++) {
		Coord cur = Coord::read();
		int val;
		scanf("%d", &val);
		start[cur] += val;
	}
	printf("%d", bfs(end, move, sizeI, sizeJ, start, state));
	return 0;
}