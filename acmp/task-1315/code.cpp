#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(n^2)
// Space complexity: O(n^2)

const int UNDEF = -1;

struct Coord {

	int i;

	int j;

	Coord()
		: i(UNDEF)
		, j(UNDEF)
	{}

	Coord(int i, int j)
		: i(i)
		, j(j)
	{}

	bool isUndef() {
		return i == UNDEF;
	}
};

void printWay(Coord start,
			  Coord end,
			  int size,
			  const std::vector<std::vector<bool>> &state,
			  const std::vector<std::vector<Coord>> &from
) {
	std::vector<std::vector<bool>> way(size, std::vector<bool>(size, false));
	while (end.i != start.i || end.j != start.j) {
		way[end.i][end.j] = true;
		end = from[end.i][end.j];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (start.i == i && start.j == j) {
				printf("@");
			} else if (end.i == i && end.j == j) {
				printf("X");
			} else if (way[i][j]) {
				printf("+");
			} else if (state[i][j]) {
				printf(".");
			} else {
				printf("O");
			}
		}
		printf("\n");
	}
}

void bfs(Coord start, Coord end, int size, std::vector<std::vector<bool>> &state) {
	std::vector<std::vector<Coord>> from(size, std::vector<Coord>(size));
	std::queue<Coord> inProcess;
	inProcess.push(start);
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		if (cur.i == end.i && cur.j == end.j) {
			printf("Y\n");
			printWay(start, end, size, state, from);
			return;
		}
		inProcess.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i * i + j * j != 1) {
					continue;
				}
				int newI = cur.i + i;
				int newJ = cur.j + j;
				if (0 <= newI && newI < size &&
					0 <= newJ && newJ < size &&
					state[newI][newJ] &&
					from[newI][newJ].isUndef()
				) {
					from[newI][newJ] = cur;
					inProcess.push({newI, newJ});
				}
			}
		}
	}
	printf("N");
}

int main() {
	int n;
	scanf("%d", &n);
	std::vector<std::vector<bool>> state(n, std::vector<bool>(n, true));
	Coord start;
	Coord end;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char val;
			scanf(" %c", &val);
			if (val == 'O') {
				state[i][j] = false;
			}
			if (val == '@') {
				start = {i, j};
			}
			if (val == 'X') {
				end = {i, j};
			}
		}
	}
	bfs(start, end, n, state);
	return 0;
}