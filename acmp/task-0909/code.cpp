#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

enum Part {
	UNMARKED, WHOLE, DESTROYED
};

struct Coord {

	int i;

	int j;
};

void bfs(int sizeI,
		 int sizeJ,
		 bool &isWhole,
		 bool &isDestroyed,
		 std::queue<Coord> &inProcess,
		 std::vector<std::vector<Part>> &field
) {
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
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
					field[newI][newJ] != Part::UNMARKED
				) {
					if (field[newI][newJ] == Part::WHOLE) {
						isWhole = true;
					}
					if (field[newI][newJ] == Part::DESTROYED) {
						isDestroyed = true;
					}
					inProcess.push({newI, newJ});
					field[newI][newJ] = Part::UNMARKED;
				}
			}
		}
	}
}

int main() {
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	std::vector<std::vector<Part>> field(sizeI, std::vector<Part>(sizeJ, Part::UNMARKED));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			char val;
			scanf(" %c", &val);
			if (val == 'S') {
				field[i][j] = Part::WHOLE;
			}
			if (val == 'X') {
				field[i][j] = Part::DESTROYED;
			}
		}
	}
	std::queue<Coord> inProcess;
	int countWhole = 0;
	int countKnocked = 0;
	int countDestroyed = 0;
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			if (field[i][j] != Part::UNMARKED) {
				bool isWhole = field[i][j] == Part::WHOLE;
				bool isDestroyed = field[i][j] == Part::DESTROYED;
				field[i][j] = Part::UNMARKED;
				inProcess.push({i, j});
				bfs(sizeI, sizeJ, isWhole, isDestroyed, inProcess, field);
				if (isWhole && !isDestroyed) {
					countWhole++;
				} else if (isDestroyed && !isWhole) {
					countDestroyed++;
				} else {
					countKnocked++;
				}
			}
		}
	}
	printf("%d %d %d", countWhole, countKnocked, countDestroyed);
	return 0;
}