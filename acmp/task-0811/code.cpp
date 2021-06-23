#include <stdio.h>
#include <vector>

// Time complexity: O(n * m)
// Space complexity: O(n * m)

struct Coord {

	int y;

	int x;

	Coord(int y, int x) :
		y(y), x(x) {}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<std::vector<char>> desk(n, std::vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &desk[i][j]);
		}
	}
	std::vector<Coord> repaintBlack;
	std::vector<Coord> repaintWhite;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Coord temp(i + 1, j + 1);
			if ((i + j) % 2 == 0) {
				if (desk[i][j] == 'B') {
					repaintBlack.push_back(temp);
				} else {
					repaintWhite.push_back(temp);
				}
			} else {
				if (desk[i][j] == 'W') {
					repaintBlack.push_back(temp);
				} else {
					repaintWhite.push_back(temp);
				}
			}
		}
	}
	std::vector<Coord> ans;
	if (repaintBlack.size() > repaintWhite.size()) {
		ans = repaintWhite;
	} else {
		ans = repaintBlack;
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < (int) ans.size(); i++) {
		printf("%d %d\n", ans[i].y, ans[i].x);
	}
	return 0;
}