#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

struct Coord {

	int i;

	int j;
};

void bfs(int sizeI,
		 int sizeJ,
		 std::queue<Coord> &inProcess,
		 std::vector<std::vector<bool>> &field
) {
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		field[cur.i][cur.j] = false;
		inProcess.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i * i + j * j != 1) {
					continue;
				}
				int newI = cur.i + i;
				int newJ = cur.j + j;
				if (0 <= newI && newI < sizeI &&
					0 <= newJ && newJ < sizeJ &&
					field[newI][newJ]
				) {
					inProcess.push({newI, newJ});
					field[newI][newJ] = false;
				}
			}
		}
	}
}

int main() {
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	std::vector<std::vector<bool>> field(sizeI, std::vector<bool>(sizeJ, false));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			char val;
			scanf(" %c", &val);
			if (val == '*') {
				field[i][j] = true;
			}
		}
	}
	std::queue<Coord> inProcess;
	int count = 0;
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			if (field[i][j]) {
				inProcess.push({i, j});
				bfs(sizeI, sizeJ, inProcess, field);
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}