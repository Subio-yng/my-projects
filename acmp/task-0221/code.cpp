#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ * nRight)
// Space complexity: O(sizeI * sizeJ * nRight)

const int UNDEF = -1;
const int N_DIRS = 4;

struct Coord {

	int i;

	int j;

	int dir;

	int nRight;
};

int bfs(Coord start,
		Coord end,
		int sizeI,
		int sizeJ,
		const std::vector<std::vector<bool>> &state
) {
	std::vector<std::vector<std::vector<std::vector<int>>>> dist(sizeI, std::vector<std::vector<std::vector<int>>>(sizeJ, std::vector<std::vector<int>>(N_DIRS, std::vector<int>(start.nRight + 1, UNDEF))));
	std::queue<Coord> inProcess;
	for (int curDir = 0; curDir < N_DIRS; curDir++) {
		dist[start.i][start.j][curDir][start.nRight] = 0;
		inProcess.push({start.i, start.j, curDir, start.nRight});
	}
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		inProcess.pop();
		if (cur.i == end.i && cur.j == end.j) {
			return dist[cur.i][cur.j][cur.dir][cur.nRight];
		}
		for (int ddir = -1; ddir <= 1; ddir++) {
			int newDir = (cur.dir + ddir + N_DIRS) % N_DIRS;
			for (int di = -1; di <= 1; di++) {
				for (int dj = -1; dj <= 1; dj++) {
					if (newDir == 0 && (di != -1 || dj != 0) ||
						newDir == 1 && (di != 0 || dj != 1) ||
						newDir == 2 && (di != 1 || dj != 0) ||
						newDir == 3 && (di != 0 || dj != -1)
					) {
						continue;
					}
					int newI = cur.i + di;
					int newJ = cur.j + dj;
					if (0 <= newI && newI < sizeI &&
						0 <= newJ && newJ < sizeJ &&
						state[newI][newJ]
					) {
						if (ddir == 1 && 
							cur.nRight > 0 &&
							dist[newI][newJ][newDir][cur.nRight - 1] == UNDEF
						) {
							dist[newI][newJ][newDir][cur.nRight - 1] = dist[cur.i][cur.j][cur.dir][cur.nRight] + 1;
							inProcess.push({newI, newJ, newDir, cur.nRight - 1});
						} else if (ddir != 1 && dist[newI][newJ][newDir][cur.nRight] == UNDEF) {
							dist[newI][newJ][newDir][cur.nRight] = dist[cur.i][cur.j][cur.dir][cur.nRight] + 1;
							inProcess.push({newI, newJ, newDir, cur.nRight});
						}
					}
				}
			}
		}
	}
	return UNDEF;
}

int main() {
	int nRight, sizeI, sizeJ;
	scanf("%d %d %d", &nRight, &sizeI, &sizeJ);
	std::vector<std::vector<bool>> state(sizeI, std::vector<bool>(sizeJ, true));
	Coord start, end;
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			char val;
			scanf(" %c", &val);
			if (val == '1') {
				state[i][j] = false;
			}
			if (val == '2') {
				start = {i, j, UNDEF, nRight};
			}
			if (val == '3') {
				end = {i, j, UNDEF, UNDEF};
			}
		}
	}
	printf("%d", bfs(start, end, sizeI, sizeJ, state));
	return 0;
}