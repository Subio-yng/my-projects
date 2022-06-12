#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(nE * log(sizeI * sizeJ))
// Space complexity: O(sizeI * sizeJ)

struct Vertex {

	int i;

	int j;

	int radiation;

	bool operator <(const Vertex &a) const {
		if (radiation == a.radiation) {
			if (i == a.i) {
				return j > a.j;
			}
			return i > a.i;
		}
		return radiation > a.radiation;
	}
};

int main() {
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	std::vector<std::vector<int>> field(sizeI, std::vector<int>(sizeJ));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	const int INF = sizeI * sizeJ * 100 + 1;
	std::vector<std::vector<bool>> isFinal(sizeI, std::vector<bool>(sizeJ, false));
	std::vector<std::vector<int>> minSumRad(sizeI, std::vector<int>(sizeJ, INF));
	std::priority_queue<Vertex> inProcess;
	minSumRad[0][0] = field[0][0];
	inProcess.push({0, 0, minSumRad[0][0]});
	while (!inProcess.empty()) {
		Vertex bestFrom = inProcess.top();
		inProcess.pop();
		if (isFinal[bestFrom.i][bestFrom.j]) {
			continue;
		}
		if (minSumRad[bestFrom.i][bestFrom.j] == INF) {
			break;
		}
		isFinal[bestFrom.i][bestFrom.j] = true;
		for (int di = -1; di <= 1; di++) {
			for (int dj = -1; dj <= 1; dj++) {
				if (di * di + dj * dj != 1) {
					continue;
				}
				int newI = bestFrom.i + di;
				int newJ = bestFrom.j + dj;
				if (0 <= newI && newI < sizeI && 0 <= newJ && newJ < sizeJ) {
					int newRad = bestFrom.radiation + field[newI][newJ];
					if (minSumRad[newI][newJ] > newRad) {
						minSumRad[newI][newJ] = newRad;
						inProcess.push({newI, newJ, newRad});
					}
				}
			}
		}
	}
	printf("%d", minSumRad[sizeI - 1][sizeJ - 1]);
	return 0;
}