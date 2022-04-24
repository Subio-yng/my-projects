#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

// Time complexity: O(size^2 * log(size^2))
// Space complexity: O(size^2 * log(size^2))

const int UNDEF = -1;

enum State {
	VOID, WAY, WALL
};

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

	bool operator <(const Coord &a) const {
		if (i == a.i) {
			return j < a.j;
		}
		return i < a.i;
	}
};

void printWay(Coord start, Coord end, std::map<Coord, Coord> &way, std::vector<std::vector<State>> &field) {
	if (start.i != end.i || start.j != end.j) {
		Coord next = way[start];
		field[next.i][next.j] = State::WAY;
		printWay(next, end, way, field);
	}
}

void bfs(Coord start,
		 Coord end,
		 int size,
		 std::vector<std::vector<State>> &field
) {
	std::map<Coord, Coord> way;
	std::queue<Coord> inProcess;
	inProcess.push(start);
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		inProcess.pop();
		if (cur.i == end.i && cur.j == end.j) {
			printWay(end, start, way, field);
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (field[i][j] == State::VOID) {
						printf(".");
					} else if (field[i][j] == State::WAY) {
						printf("@");
					} else {
						printf("#");
					}
				}
				printf("\n");
			}
			return;
		}
		for (int di = -2; di <= 2; di++) {
			for (int dj = -2; dj <= 2; dj++) {
				if (di * di + dj * dj != 5) {
					continue;
				}
				int newI = cur.i + di;
				int newJ = cur.j + dj;
				if (0 <= newI && newI < size &&
					0 <= newJ && newJ < size &&
					field[newI][newJ] != State::WALL &&
					way.find({newI, newJ}) == way.end()
				) {
					way[{newI, newJ}] = cur;
					inProcess.push({newI, newJ});
				}
			}
		}
	}
	printf("Impossible");
}

int main() {
	int size;
	scanf("%d", &size);
	std::vector<std::vector<State>> field(size, std::vector<State>(size, State::VOID));
	Coord start, end;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			char val;
			scanf(" %c", &val);
			if (val == '#') {
				field[i][j] = State::WALL;
			}
			if (val == '@') {
				field[i][j] = State::WAY;
				if (start.i == UNDEF) {
					start = {i, j};
				} else {
					end = {i, j};
				}
			}
		}
	}
	bfs(start, end, size, field);
	return 0;
}