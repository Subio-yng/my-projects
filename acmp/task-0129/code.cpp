#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

struct Coord {

	int i;

	int j;
};

const int UNDEF = -1;

void bfs(int sizeI, int sizeJ, std::queue<Coord> &inProcess, std::vector<std::vector<int>> &dist) {
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		inProcess.pop();
		for (int moveI = -1; moveI <= 1; moveI++) {
			for (int moveJ = -1; moveJ <= 1; moveJ++) {
				if (moveI * moveI + moveJ * moveJ != 1) {
					continue;
				}
				int newI = cur.i + moveI;
				int newJ = cur.j + moveJ;
				if (0 <= newI && newI < sizeI && 
					0 <= newJ && newJ < sizeJ &&
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
	std::vector<std::vector<int>> dist(sizeI, std::vector<int>(sizeJ, UNDEF));
	std::queue<Coord> inProcess;
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			char val;
			scanf(" %c", &val);
			if (val == '1') {
				dist[i][j] = 0;
				inProcess.push({i, j});
			}
		}
	}
	bfs(sizeI, sizeJ, inProcess, dist);
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}