#include <stdio.h>
#include <vector>
#include <queue>

// Time complexity: O(sizeI * sizeJ)
// Space complexity: O(sizeI * sizeJ)

struct Coord {

	int i;

	int j;
};

const int UNDEF = -1;

void bfs(Coord start,
         int sizeI,
         int sizeJ,
         const std::vector<std::vector<bool>> &field,
         std::vector<std::vector<int>> &dist
) {
    std::queue<Coord> inProcess;
    inProcess.push(start);
    dist[start.i][start.j] = 0;
    while (!inProcess.empty()) {
        Coord cur = inProcess.front();
        inProcess.pop();
        for (int iMove = -1; iMove <= 1; iMove++) {
            for (int jMove = -1; jMove <= 1; jMove++) {
                if (iMove * iMove + jMove * jMove != 1) {
                    continue;
                }
                int newI = cur.i + iMove;
                int newJ = cur.j + jMove;
                if (0 <= newI && newI < sizeI &&
                    0 <= newJ && newJ < sizeJ &&
                    field[newI][newJ] &&
                    dist[newI][newJ] == UNDEF
                ) {
                    dist[newI][newJ] = dist[cur.i][cur.j] + 1;
                    inProcess.push({newI, newJ});
                }
            }
        }
    }
}
int main() {
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	std::vector<std::vector<bool>> field(sizeI, std::vector<bool>(sizeJ, false));
	Coord tiger;
	Coord slave = {1, 1};
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			char val;
			scanf(" %c", &val);
			if (val != '#') {
				field[i][j] = true;
			}
			if (val == 'T') {
				tiger = {i, j};
			}
		}
	}
	std::vector<std::vector<int>> distSlave(sizeI, std::vector<int>(sizeJ, UNDEF));
	bfs(slave, sizeI, sizeJ, field, distSlave);
	std::vector<std::vector<int>> distTiger(sizeI, std::vector<int>(sizeJ, UNDEF));
	bfs(tiger, sizeI, sizeJ, field, distTiger);
	printf("%d\n", distSlave[sizeI - 2][sizeJ - 2]);
	if (distTiger[sizeI - 2][sizeJ - 2] == UNDEF ||
        distSlave[sizeI - 2][sizeJ - 2] < distTiger[sizeI - 2][sizeJ - 2]
	) {
        printf("Yes");
	} else {
        printf("No");
	}
	return 0;
}