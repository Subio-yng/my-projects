#include <stdio.h>
#include <algorithm>

// Time complexity: O(countThrows)
// Space complexity: O(1)

int main() {
    int length;
    scanf("%d", &length);
    int countThrows;
    scanf("%d", &countThrows);
    int player1 = 0, player2 = 0;
    bool move = true;
    for (int i = 0; i < countThrows; i++) {
        int score;
        scanf("%d", &score);
        if (player1 < length && player2 < length) {
            if (move) {
                player1 = std::min((player1 + score), length);
            } else {
                player2 = std::min((player2 + score), length);
            }
            if (score < 6) {
                move = !move;
            }
        }
    }
    printf("%d\n%d", player1, player2);
    return 0;
}