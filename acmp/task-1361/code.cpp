#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>

// Time complexity: O(1)
// Space complexity: O(1)

std::string getShift(const std::string &str, int len) {
	std::string newStr;
	for (int i = 0; i < len; i++) {
		newStr += str[(len + i - 1) % len];
	}
	return newStr;
}

void bfs(const std::string &start,
		 const std::string &end,
		 int len
) {
	std::map<std::string, std::vector<std::string>> way;
	std::queue<std::string> inProcess;
	inProcess.push(start);
	while (!inProcess.empty()) {
		auto cur = inProcess.front();
		way[cur].push_back(cur);
		inProcess.pop();
		if (cur == end) {
			break;
		}
		std::string next = cur;
		if (next[0] < '9') {
			next[0]++;
			if (way[next].empty()) {
				way[next] = way[cur];
				inProcess.push(next);
			}
			next[0]--;
		}
		if (next[len - 1] > '1') {
			next[len - 1]--;
			if (way[next].empty()) {
				way[next] = way[cur];
				inProcess.push(next);
			}
			next[len - 1]++;
		}
		next = getShift(next, len);
		if (way[next].empty()) {
			way[next] = way[cur];
			inProcess.push(next);
		}
		next = cur;
		std::reverse(next.begin(), next.end());
		next = getShift(next, len);
		std::reverse(next.begin(), next.end());
		if (way[next].empty()) {
			way[next] = way[cur];
			inProcess.push(next);
		}
	}
	for (auto next : way[end]) {
		printf("%s\n", next.c_str());
	}
}

int main() {
	const int LENGTH = 4;
	std::string start(LENGTH, ' ');
	for (int i = 0; i < LENGTH; i++) {
		scanf(" %c", &start[i]);
	}
	std::string end(LENGTH, ' ');
	for (int i = 0; i < LENGTH; i++) {
		scanf(" %c", &end[i]);
	}
	bfs(start, end, LENGTH);
	return 0;
}