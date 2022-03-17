#include <stdio.h>
#include <vector>

// Time complexity: O(nV^2)
// Space complexity: O(nV^2)

void dfs(int curV, int &count, std::vector<bool> &visited, const std::vector<std::vector<bool>> &edges) {
    visited[curV] = true;
    for (int nextV = 0; nextV < (int) edges.size(); nextV++) {
        if (edges[curV][nextV] && !visited[nextV]) {
            count++;
            dfs(nextV, count, visited, edges);
        }
    }
}

int main() {
	int nV;
	scanf("%d", &nV);
	std::vector<std::vector<bool>> edges(nV, std::vector<bool>(nV, false));
	int nE = 0;
	for (int i = 0; i < nV; i++) {
		for (int j = 0; j < nV; j++) {
			char val;
			scanf(" %c", &val);
			if (val == '1') {
				edges[i][j] = true;
				nE++;
			}
		}
	}
	nE /= 2;
	int count = 0;
	std::vector<bool> visited(nV, false);
	dfs(0, count, visited, edges);
	if (nE == nV - 1 && count == nV - 1) {
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}