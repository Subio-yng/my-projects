#include <stdio.h>
#include <queue>
#include <vector>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

struct Coord {

	int i;

	int j;

	static Coord read() {
		int i, j;
		scanf("%d %d", &i, &j);
		return {i - 1, j - 1};
	}
};

const int UNDEF = -1;

int bfs(Coord start,
		int sizeI,
		int sizeJ,
		std::vector<std::vector<int>> &dist, 
		const std::vector<std::vector<bool>> &field
) {
	std::queue<Coord> inProcess;
	inProcess.push(start);
	dist[start.i][start.j] = 0;
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		if (cur.i == 0 || cur.j == 0 || cur.i == sizeI - 1 || cur.j == sizeJ - 1) {
			return dist[cur.i][cur.j] + 1;
		}
		inProcess.pop();
		for (int iMove = -1; iMove <= 1; iMove++) {
			for (int jMove = -1; jMove <= 1; jMove++) {
				if (iMove != 0 && 
					(cur.i % 2 == 0 && jMove == 1 || 
					cur.i % 2 == 1 && jMove == -1)
				) {
					continue;
				}
				int newI = cur.i + iMove;
				int newJ = cur.j + jMove;
				if (0 <= newI && newI < sizeI &&
					0 <= newJ && newJ < sizeJ &&
					field[newI][newJ] && 
					dist[newI][newJ] == UNDEF
				) {
					dist[newI][newJ] = dist[cur.i][cur.j] + 1;
					inProcess.push({newI, newJ});
				}
			}
		}
	}
	return UNDEF;
}

int main() {
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	Coord start = Coord::read();
	std::vector<std::vector<bool>> field(sizeI, std::vector<bool>(sizeJ, false));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			char val;
			scanf(" %c", &val);
			if (val == '1') {
				field[i][j] = true;
			}
		}
	}
	std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
	int minDist = bfs(start, sizeI, sizeJ, dist, field);
	if (minDist == -1) {
		printf("No solution");
	} else {
		printf("%d", minDist);
	}
	return 0;
}