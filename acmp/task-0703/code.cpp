#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

const int SIZE = 3;
const int UNDEF = -1;

enum State {
	VOID, WHITE, BLACK
};

int bfs(const std::vector<std::vector<State>> &start,
		const std::vector<std::vector<State>> &end
) {
	std::map<std::vector<std::vector<State>>, int> dist;
	std::queue<std::vector<std::vector<State>>> inProcess;
	inProcess.push(start);
	dist[start] = 0;
	while (!inProcess.empty()) {
		auto cur = inProcess.front();
		inProcess.pop();
		if (cur == end) {
			return dist[end];
		}
		for (int curI = 0; curI < SIZE; curI++) {
			for (int curJ = 0; curJ < SIZE; curJ++) {
				if (cur[curI][curJ] != State::VOID) {
					for (int di = -2; di <= 2; di++) {
						for (int dj = -2; dj <= 2; dj++) {
							if (di * di + dj * dj != 5) {
								continue;
							}
							int newI = curI + di;
							int newJ = curJ + dj;
							if (0 <= newI && newI < SIZE &&
								0 <= newJ && newJ < SIZE &&
								cur[newI][newJ] == State::VOID
							) {
								std::vector<std::vector<State>> next = cur;
								next[curI][curJ] = State::VOID;
								next[newI][newJ] = cur[curI][curJ];
								if (dist.find(next) == dist.end()) {
									dist[next] = dist[cur] + 1;
									inProcess.push(next);
								}
							}
						}
					}
				}
			}
		}
	}
	return UNDEF;
}

int main() {
	std::vector<std::vector<State>> start(SIZE, std::vector<State>(SIZE, State::VOID));
	std::vector<std::vector<State>> end(SIZE, std::vector<State>(SIZE, State::VOID));
	for (int i = 0; i < SIZE; i++) {
		char val;
		for (int j = 0; j < SIZE; j++) {
			scanf(" %c", &val);
			if (val == 'W') {
				start[i][j] = State::WHITE;
			}
			if (val == 'B') {
				start[i][j] = State::BLACK;
			}
		}
		for (int j = 0; j < SIZE; j++) {
			scanf(" %c", &val);
			if (val == 'W') {
				end[i][j] = State::WHITE;
			}
			if (val == 'B') {
				end[i][j] = State::BLACK;
			}
		}
	}
	printf("%d", bfs(start, end));
	return 0;
}