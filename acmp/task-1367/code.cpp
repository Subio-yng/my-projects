#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

// Time complexity: O(mod * len)
// Space complexity: O(mod * len)

const int UNDEF = -1;

void bfs(int startV,
		 int endV,
		 std::vector<int> &dist,
		 const std::vector<std::vector<int>> &edges
) {
	std::queue<int> inProcess;
	dist[startV] = 0;
	inProcess.push(startV);
	while (!inProcess.empty()) {
		int curV = inProcess.front();
		inProcess.pop();
		if (curV == endV) {
			return;
		}
		for (int nextV : edges[curV]) {
			if (dist[nextV] == UNDEF) {
				dist[nextV] = dist[curV] + 1;
				inProcess.push(nextV);
			}
		}
	}
}

int main() {
	char buf[1000 + 1];
	int mod;
	scanf("%1000s %d", buf, &mod);
	std::string str(buf);
	int dSize;
	scanf("%d", &dSize);
	std::vector<int> digits(dSize);
	for (int i = 0; i < dSize; i++) {
		scanf("%d", &digits[i]);
	}
	std::sort(digits.begin(), digits.end());
	int endV = 0;
	for (int i = 0; i < (int) str.length(); i++) {
		endV = (endV * 10 + (str[i] - '0')) % mod;
	}
	std::vector<std::vector<int>> edges(mod);
	for (int from = 0; from < mod; from++) {
		for (int i = 0; i < dSize; i++) {
			int to = (from * 10 + digits[i]) % mod;
			edges[to].push_back(from);
		}
	}
	int startV = 0;
	std::vector<int> dist(mod, UNDEF);
	bfs(startV, endV, dist, edges);
	if (dist[endV] == UNDEF) {
		printf("-1");
		return 0;
	}
	printf("%s", str.c_str());
	while (endV != startV) {
		for (int i = 0; i < dSize; i++) {
			int prevV = (endV * 10 + digits[i]) % mod;
			if (dist[prevV] == dist[endV] - 1) {
				printf("%d", digits[i]);
				endV = prevV;
				break;
			}
		}
	}
	return 0;
}