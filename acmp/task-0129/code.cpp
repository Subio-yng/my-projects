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
		if (cur.i + 1 < sizeI && dist[cur.i + 1][cur.j] == UNDEF) {
			dist[cur.i + 1][cur.j] = dist[cur.i][cur.j] + 1;
			inProcess.push({cur.i + 1, cur.j});
		}
		if (0 <= cur.i - 1 && dist[cur.i - 1][cur.j] == UNDEF) {
			dist[cur.i - 1][cur.j] = dist[cur.i][cur.j] + 1;
			inProcess.push({cur.i - 1, cur.j});
		}
		if (cur.j + 1 < sizeJ && dist[cur.i][cur.j + 1] == UNDEF) {
			dist[cur.i][cur.j + 1] = dist[cur.i][cur.j] + 1;
			inProcess.push({cur.i, cur.j + 1});
		}
		if (0 <= cur.j - 1 && dist[cur.i][cur.j - 1] == UNDEF) {
			dist[cur.i][cur.j - 1] = dist[cur.i][cur.j] + 1;
			inProcess.push({cur.i, cur.j - 1});
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