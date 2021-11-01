#include <stdio.h>
#include <algorithm>
#include <vector>

// Time complexity: O(countThrows)
// Space complexity: O(1)

int main() {
	const int N_PLAYERS = 2;
	int length;
	scanf("%d", &length);
	int countThrows;
	scanf("%d", &countThrows);
	std::vector<int> pos(N_PLAYERS, 0);
	int iPlayer = 0;
	for (int i = 0; i < countThrows; i++) {
		int score;
		scanf("%d", &score);
		if (pos[0] >= length || pos[1] >= length) {
			break;
		}
		pos[iPlayer] = std::min(pos[iPlayer] + score, length);
		if (score != 6) {
			iPlayer = N_PLAYERS - 1 - iPlayer;
		}
	}
	printf("%d\n%d", pos[0], pos[1]);
	return 0;
}