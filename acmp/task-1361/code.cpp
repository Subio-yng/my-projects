#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

// Time complexity: O(1)
// Space complexity: O(1)

const int LENGTH = 1000;

void bfs(int start, int end) {
	std::map<int, std::vector<int>> way;
	std::queue<int> inProcess;
	inProcess.push(start);
	while (!inProcess.empty()) {
		int cur = inProcess.front();
		inProcess.pop();
		way[cur].push_back(cur);
		if (cur / LENGTH < 9 && way[cur + LENGTH].empty()) {
			way[cur + LENGTH] = way[cur];
			inProcess.push(cur + LENGTH);
		}
		if (cur % 10 > 1 && way[cur - 1].empty()) {
			way[cur - 1] = way[cur];
			inProcess.push(cur - 1);
		}
		int rightShift = cur % 10 * LENGTH + cur / 10;
		if (way[rightShift].empty()) {
			way[rightShift] = way[cur];
			inProcess.push(rightShift);
		}
		int leftShift = cur % LENGTH * 10 + cur / LENGTH;
		if (way[leftShift].empty()) {
			way[leftShift] = way[cur];
			inProcess.push(leftShift);
		}
	}
	for (auto next : way[end]) {
		printf("%d\n", next);
	}
}

int main() {
	int start, end;
	scanf("%d %d", &start, &end);
	bfs(start, end);
	return 0;
}