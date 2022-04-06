#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(nV^2)
// Space complexity: O(nV^2)

struct Coord {

	int i;

	int j;

	static Coord read() {
		int i, j;
		scanf("%d %d", &i, &j);
		return {i - 1, j - 1};
	}
};

std::vector<Coord> MOVE = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void bfs(Coord startV,
		 Coord endV,
		 int size,
		 std::vector<std::vector<int>> &dist,
		 std::queue<Coord> &inProcess,
		 std::vector<std::vector<bool>> &visited
) {
	dist[startV.i][startV.j] = 0;
	inProcess.push(startV);
	visited[startV.i][startV.j] = true;
	while (!inProcess.empty()) {
		Coord curV = inProcess.front();
		inProcess.pop();
		if (curV.i == endV.i && curV.j == endV.j) {
			return;
		}
		for (int m = 0; m < 8; m++) {
			int newI = curV.i + MOVE[m].i;
			int newJ = curV.j + MOVE[m].j;
			if (0 <= newI && newI < size &&
				0 <= newJ && newJ < size &&
				!visited[newI][newJ]
			) {
				visited[newI][newJ] = true;
				dist[newI][newJ] = dist[curV.i][curV.j] + 1;
				inProcess.push({newI, newJ});
			}
		}
	}
}

int main() {
	const int UNDEF = -1;
	int nV;
	scanf("%d", &nV);
	std::vector<std::vector<bool>> visited(nV, std::vector<bool>(nV, false));
	Coord startV = Coord::read();
	Coord endV = Coord::read();
	std::queue<Coord> inProcess;
	std::vector<std::vector<int>> dist(nV, std::vector<int>(nV, UNDEF));
	bfs(startV, endV, nV, dist, inProcess, visited);
	printf("%d", dist[endV.i][endV.j]);
	return 0;
}