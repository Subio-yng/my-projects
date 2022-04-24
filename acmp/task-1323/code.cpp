#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(size^3)
// Space complexity: O(size^3)

const int UNDEF = -1;

struct Coord {

	int z;

	int i;

	int j;
};

int bfs(Coord start,
		Coord end,
		int size,
		const std::vector<std::vector<std::vector<bool>>> &state
) {
	std::vector<std::vector<std::vector<int>>> dist(size, std::vector<std::vector<int>>(size, std::vector<int>(size, UNDEF)));
	std::queue<Coord> inProcess;
	inProcess.push(start);
	dist[start.z][start.i][start.j] = 0;
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		inProcess.pop();
		if (cur.z == end.z) {
			return dist[cur.z][cur.i][cur.j];
		}
		for (int dz = -1; dz <= 1; dz++) {
			for (int di = -1; di <= 1; di++) {
				for (int dj = -1; dj <= 1; dj++) {
					if (dz * dz + di * di + dj * dj != 1) {
						continue;
					}
					int newZ = cur.z + dz;
					int newI = cur.i + di;
					int newJ = cur.j + dj;
					if (0 <= newZ && newZ < size &&
						0 <= newI && newI < size &&
						0 <= newJ && newJ < size &&
						state[newZ][newI][newJ] &&
						dist[newZ][newI][newJ] == UNDEF
					) {
						dist[newZ][newI][newJ] = dist[cur.z][cur.i][cur.j] + 1;
						inProcess.push({newZ, newI, newJ});
					}
				}
			}
		}
	}
	return UNDEF;
}

int main() {
	int size;
	scanf("%d", &size);
	std::vector<std::vector<std::vector<bool>>> state(size, std::vector<std::vector<bool>>(size, std::vector<bool>(size, true)));
	Coord start;
	for (int z = 0; z < size; z++) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				char val;
				scanf(" %c", &val);
				if (val == '#') {
					state[z][i][j] = false;
				}
				if (val == 'S') {
					start = {z, i, j};
				}
			}
		}
	}
	printf("%d", bfs(start, {0, UNDEF, UNDEF}, size, state));
	return 0;
}