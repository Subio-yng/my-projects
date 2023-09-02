#include <bits/stdc++.h>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

enum State {
	VOID, FOREST, WATER
};

struct Coord {

	int i;

	int j;

	static Coord read() {
		int i, j;
		scanf("%d %d", &i, &j);
		return {i - 1, j - 1};
	}
};

int bfs(Coord start,
		Coord end,
		int sizeI,
		int sizeJ,
		std::vector<std::vector<State>> &field
) {
	static const int UNDEF = -1;
	std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
	std::queue<Coord> inProcess;
	inProcess.push(start);
	dist[start.i][start.j] = 0;
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		inProcess.pop();
		if (field[cur.i][cur.j] == State::FOREST) {
			dist[cur.i][cur.j]++;
			field[cur.i][cur.j] = State::VOID;
			inProcess.push(cur);
			continue;
		}
		if (cur.i == end.i && cur.j == end.j) {
			break;
		}
		for (int di = -1; di <= 1; di++) {
			for (int dj = -1; dj <= 1; dj++) {
				if (di * di + dj * dj != 1) {
					continue;
				}
				int nextI = cur.i + di;
				int nextJ = cur.j + dj;
				if (0 <= nextI && nextI < sizeI &&
					0 <= nextJ && nextJ < sizeJ &&
					field[nextI][nextJ] != State::WATER &&
					dist[nextI][nextJ] == UNDEF
				) {
					dist[nextI][nextJ] = dist[cur.i][cur.j] + 1;
					inProcess.push({nextI, nextJ});
				}
			}
		}
	}
	return dist[end.i][end.j];
}

int main() {
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	Coord start = Coord::read();
	Coord end = Coord::read();
	std::vector<std::vector<State>> field(sizeI, std::vector<State>(sizeJ, State::VOID));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			char val;
			scanf(" %c", &val);
			if (val == 'W') {
				field[i][j] = State::FOREST;
			} else if (val == '#') {
				field[i][j] = State::WATER;
			}
		}
	}
	field[start.i][start.j] = State::VOID;
	printf("%d", bfs(start, end, sizeI, sizeJ, field));
	return 0;
}
