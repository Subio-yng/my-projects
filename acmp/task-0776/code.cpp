#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ * battery)
// Space complexity: O(sizeI * sizeJ * battery)

const int UNDEF = -1;

struct Coord {
	
	int i;

	int j;

	int restBattery;

	static Coord read() {
		int j, i;
		scanf("%d %d", &j, &i);
		return {i - 1, j - 1, UNDEF};
	}
};

int bfs(Coord start, 
		Coord end, 
		int sizeI, 
		int sizeJ, 
		int power, 
		const std::vector<std::vector<int>> &field
) {
	std::vector<std::vector<std::vector<int>>> dist(sizeI, std::vector<std::vector<int>>(sizeJ, std::vector<int>(start.restBattery + 1, UNDEF)));
	std::queue<Coord> inProcess;
	inProcess.push(start);
	dist[start.i][start.j][start.restBattery] = 0;
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		inProcess.pop();
		if (cur.i == end.i && cur.j == end.j) {
			return dist[cur.i][cur.j][cur.restBattery];
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
					field[newI][newJ] != 0 &&
					abs(field[newI][newJ] - field[cur.i][cur.j]) <= 1 &&
					dist[newI][newJ][cur.restBattery] == UNDEF
				) {
					dist[newI][newJ][cur.restBattery] = dist[cur.i][cur.j][cur.restBattery] + 1;
					inProcess.push({newI, newJ, cur.restBattery});
				}
				if (cur.restBattery == 0) {
					continue;
				}
				int maxH = field[cur.i][cur.j];
				int curPower = 1;
				while (0 <= newI && newI < sizeI && 0 <= newJ && newJ < sizeJ && curPower <= power) {
					if (field[newI][newJ] > maxH) {
						curPower += field[newI][newJ] - maxH;
						maxH = field[newI][newJ];
					}
					if (field[newI][newJ] != 0 &&
						curPower + maxH - field[newI][newJ] <= power && 
						dist[newI][newJ][cur.restBattery - 1] == UNDEF
					) {
						dist[newI][newJ][cur.restBattery - 1] = dist[cur.i][cur.j][cur.restBattery] + 1;
						inProcess.push({newI, newJ, cur.restBattery - 1});
					}
					newI += di;
					newJ += dj;
					curPower++;
				}
			}
		}
	}
	return UNDEF;
}

int main() {
	int sizeJ, sizeI;
	scanf("%d %d", &sizeJ, &sizeI);
	Coord end = Coord::read();
	int battery, power;
	scanf("%d %d", &battery, &power);
	std::vector<std::vector<int>> field(sizeI, std::vector<int>(sizeJ));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	int move = bfs({0, 0, battery}, end, sizeI, sizeJ, power, field);
	if (move == UNDEF) {
		printf("IMPOSSIBLE");
	} else {
		printf("%d", move);
	}
	return 0;
}