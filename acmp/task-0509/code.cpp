#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <queue>

// Time complexity: O(1)
// Space complexity: O(1)

int bfs(int sizeI,
		int sizeJ,
		const std::vector<std::string> &sample,
		std::vector<std::string> &field
) {
	std::map<std::vector<std::string>, int> dist;
	dist[field] = 1;
	std::queue<std::vector<std::string>> inProcess;
	inProcess.push(field);
	while (!inProcess.empty()) {
		auto cur = inProcess.front();
		inProcess.pop();
		if (cur == sample) {
			return dist[cur] - 1;
		}
		for (int curI = 0; curI < sizeI; curI++) {
			for (int curJ = 0; curJ < sizeJ; curJ++) {
				if (cur[curI][curJ] == '#') {
					for (int iMove = -1; iMove <= 1; iMove++) {
						for (int jMove = -1; jMove <= 1; jMove++) {
							if (jMove * jMove + iMove * iMove != 1) {
								continue;
							}
							int newI = curI + iMove;
							int newJ = curJ + jMove;
							if (0 <= newI && newI < sizeI &&
								0 <= newJ && newJ < sizeJ
							) {
								std::vector<std::string> temp = cur;
								std::swap(temp[newI][newJ], temp[curI][curJ]);
								if (dist[temp] == 0) {
									dist[temp] = dist[cur] + 1;
									inProcess.push(temp);
								}
							}
						}
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	const int SIZE_I = 2;
	const int SIZE_J = 4;
	std::vector<std::string> sample(SIZE_I, std::string(SIZE_J, ' '));
	for (int i = 0; i < SIZE_I; i++) {
		for (int j = 0; j < SIZE_J; j++) {
			scanf(" %c", &sample[i][j]);
		}
	}
	std::vector<std::string> field(SIZE_I, std::string(SIZE_J, ' '));
	for (int i = 0; i < SIZE_I; i++) {
		for (int j = 0; j < SIZE_J; j++) {
			scanf(" %c", &field[i][j]);
		}
	}
	printf("%d", bfs(SIZE_I, SIZE_J, sample, field));
	return 0;
}