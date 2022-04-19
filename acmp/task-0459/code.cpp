#include <stdio.h>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

// Time complexity: O(len^2)
// Space complexity: O(len^2)

const std::vector<char> MOVE = {'N', 'E', 'S', 'W'};

struct Coord {

	int i;
	
	int j;

	bool operator <(const Coord &a) const {
		if (i == a.i) {
			return j < a.j;
		}
		return i < a.i;
	}

	void getNext(char move, int coef) {
		if (move == 'N') {
			i += coef;
		}
		if (move == 'E') {
			j += coef;
		}
		if (move == 'S') {
			i -= coef;
		}
		if (move == 'W') {
			j -= coef;
		}
	}
};

void printWay(std::map<Coord, char> &way, Coord start, Coord end) {
	char cur = way[start];
	if (start.i != end.i || start.j != end.j) {
		start.getNext(way[start], -2);
		printWay(way, start, end);
	} else {
		return;
	}
	printf("%c", cur);
}

void bfs(Coord start, 
		 Coord end, 
		 int sizeI, 
		 int sizeJ, 
		 const std::vector<std::vector<bool>> &state
) {
	std::map<Coord, char> way;
	std::queue<Coord> inProcess;
	inProcess.push(start);
	while (!inProcess.empty()) {
		Coord cur = inProcess.front();
		inProcess.pop();
		if (cur.i == end.i && cur.j == end.j) {
			break;
		}
		for (char next : MOVE) {
			Coord newC = cur;
			newC.getNext(next, 1);
			if (0 <= newC.i && newC.i < sizeI &&
				0 <= newC.j && newC.j < sizeJ &&
				state[newC.i][newC.j] &&
				way.find({newC}) == way.end()
			) {
				way[newC] = next;
				inProcess.push(newC);
			}
		}
	}
	printWay(way, end, start);
}

int main() {
	char buf[1 + 200];
	scanf(" %s", &buf);
	std::string route(buf);
	int minI = 0;
	int maxI = 0;
	int minJ = 0;
	int maxJ = 0;
	Coord end = {0, 0};
	for (int w = 0; w < (int) route.length(); w++) {
		end.getNext(route[w], 2);
		minI = std::min(minI, end.i);
		maxI = std::max(maxI, end.i);
		minJ = std::min(minJ, end.j);
		maxJ = std::max(maxJ, end.j);
	}
	int sizeI = maxI - minI + 1;
	int sizeJ = maxJ - minJ + 1;
	Coord start = {-minI, -minJ};
	std::vector<std::vector<bool>> state(sizeI, std::vector<bool>(sizeJ, false));
	state[start.i][start.j] = true;
	end = start;
	for (int w = 0; w < (int) route.length(); w++) {
		end.getNext(route[w], 1);
		state[end.i][end.j] = true;
		end.getNext(route[w], 1);
		state[end.i][end.j] = true;
	}
	bfs(end, start, sizeI, sizeJ, state);
	return 0;
}