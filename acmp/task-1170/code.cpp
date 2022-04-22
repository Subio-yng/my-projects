#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

const int UNDEF = -1;

enum State {
	VOID, WALL, DOOR
};

struct Coord {

	int i;

	int j;
};

void bfs(Coord start, 
		 Coord key, 
		 bool haveKey, 
		 int sizeI, 
		 int sizeJ, 
		 const std::vector<std::vector<State>> &field
) {
	std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
	std::queue<Coord> inProcess;
	inProcess.push(start);
	dist[start.i][start.j] = 0;
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		inProcess.pop();
		if (cur.i == 0 || cur.j == 0 || cur.i == sizeI - 1 || cur.j == sizeJ - 1) {
			printf("%d", dist[cur.i][cur.j] + 1);
			return;
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
					(field[newI][newJ] == State::VOID ||
					 haveKey && field[newI][newJ] == State::DOOR) &&
					dist[newI][newJ] == UNDEF
				) {
					dist[newI][newJ] = dist[cur.i][cur.j] + 1;
					inProcess.push({newI, newJ});
				}
			}
		}
	}
	printf("No way ");
	if (!haveKey) {
		if (dist[key.i][key.j] == UNDEF) {
			printf("No key");
		} else {
			printf("%d ", dist[key.i][key.j]);
			bfs(key, key, true, sizeI, sizeJ, field);
		}
	}
}

int main() {
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	std::vector<std::vector<State>> field(sizeI, std::vector<State>(sizeJ, State::VOID));
	Coord start;
	Coord key;
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			char val;
			scanf(" %c", &val);
			if (val == 'T') {
				start = {i, j};
			}
			if (val == 'K') {
				key = {i, j};
			}
			if (val == '#') {
				field[i][j] = State::WALL;
			}
			if (val == '-') {
				field[i][j] = State::DOOR;
			}
		}
	}
	bfs(start, key, false, sizeI, sizeJ, field);
	return 0;
}