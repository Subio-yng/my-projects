#include <stdio.h>
#include <math.h>
#include <vector>

// Time complexity: O(nV^2 * log(range))
// Space complexity: O(nV^2)

enum Part {
	UNMARKED, LEFT, RIGHT
};

Part getOppositePart(const Part &cur) {
    if (cur == Part::LEFT) {
        return Part::RIGHT;
    } else if (cur == Part::RIGHT) {
        return Part::LEFT;
    } else {
        throw 1;
    }
}

struct Coord {

	int x;

	int y;

	static Coord read() {
		int x, y;
		scanf("%d %d", &x, &y);
		return {x, y};
	}

	int getDistanceTo(const Coord &c) {
		int dx = x - c.x;
		int dy = y - c.y;
		return dx * dx + dy * dy;
	}
};

bool dfs(int curV, Part curColor, std::vector<Part> &colors, const std::vector<std::vector<int>> &edges) {
    colors[curV] = curColor;
    for (int nextV : edges[curV]) {
        bool isBipartite = true;
        if (colors[nextV] == Part::UNMARKED) {
            isBipartite = dfs(nextV, getOppositePart(curColor), colors, edges);
        } else {
            isBipartite = colors[curV] != colors[nextV];
        }
        if (!isBipartite) {
            return false;
        }
    }
    return true;
}

int main() {
	int nV;
	scanf("%d", &nV);
	std::vector<Coord> listV(nV);
	for (int i = 0; i < nV; i++) {
		listV[i] = Coord::read();
	}
	int leftDist = 0;
	int rightDist = 20000 * 20000 * 2 + 1;
	std::vector<Part> ansColors(nV);
	while (leftDist + 1 < rightDist) {
		int midDist = leftDist + ((rightDist - leftDist) / 2);
		std::vector<std::vector<int>> edges(nV);
		for (int v1 = 0; v1 < nV; v1++) {
			for (int v2 = v1 + 1; v2 < nV; v2++) {
				if (listV[v1].getDistanceTo(listV[v2]) < midDist) {
					edges[v1].push_back(v2);
					edges[v2].push_back(v1);
				}
			}
		}
		bool check = true;
		std::vector<Part> curColors(nV, Part::UNMARKED);
		for (int curV = 0; curV < nV && check; curV++) {
			if (curColors[curV] == Part::UNMARKED) {
				check = dfs(curV, Part::LEFT, curColors, edges);
			}
		}
		if (check) {
			leftDist = midDist;
			ansColors.swap(curColors);
		} else {
			rightDist = midDist;
		}
	}
	printf("%.8f\n", sqrt(leftDist) / 2.0);
	for (int i = 0; i < nV; i++) {
		if (ansColors[i] == Part::LEFT) {
			printf("1 ");
		} else {
			printf("2 ");
		}
	}
	return 0;
}