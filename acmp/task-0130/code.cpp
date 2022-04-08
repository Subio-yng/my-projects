#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(1)
// Space complexity: O(1)

struct Coord {

	int i;

	int j;

	static Coord read() {
		char i, j;
		scanf(" %c%c", &i, &j);
		return {i - 'a', j - '1'};
	}
};

const int UNDEF = -1;

void bfs(Coord startV,
		 Coord endV,
		 int size,
		 std::vector<std::vector<int>> &dist,
		 std::queue<Coord> &inProcess
) {
	dist[startV.i][startV.j] = 0;
	inProcess.push(startV);
	while (!inProcess.empty()) {
		Coord curV = inProcess.front();
		inProcess.pop();
		if (curV.i == endV.i && curV.j == endV.j) {
			return;
		}
		for (int moveI = -2; moveI <= 2; moveI++) {
			for (int moveJ = -2; moveJ <= 2; moveJ++) {
				if (moveI * moveI + moveJ * moveJ != 5) {
					continue;
				}
				int newI = curV.i + moveI;
				int newJ = curV.j + moveJ;
				if (0 <= newI && newI < size &&
					0 <= newJ && newJ < size &&
					dist[newI][newJ] == UNDEF
				) {
					dist[newI][newJ] = dist[curV.i][curV.j] + 1;
					inProcess.push({newI, newJ});
				}
			}
		}
	}
}

int main() {
	const int SIZE = 8;
	Coord startV = Coord::read();
	Coord endV = Coord::read();
	std::queue<Coord> inProcess;
	std::vector<std::vector<int>> dist(SIZE, std::vector<int>(SIZE, UNDEF));
	bfs(startV, endV, SIZE, dist, inProcess);
	if (dist[endV.i][endV.j] % 2 == 0) {
		printf("%d", dist[endV.i][endV.j] / 2);
	} else {
		printf("-1");
	}
	return 0;
}