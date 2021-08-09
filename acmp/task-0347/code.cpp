#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(1)
// Space complexity: O(1)

int main() {
    std::vector<int> cards(5);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &cards[i]);
    }
    std::sort(cards.begin(), cards.end());
    if (cards[0] == cards[1] && cards[1] == cards[2] &&
        cards[2] == cards[3] && cards[3] == cards[4]
    ) {
        printf("Impossible");
    } else if (cards[1] == cards[2] && cards[2] == cards[3] &&
               cards[0] != cards[4] && (cards[0] == cards[1] ||
               cards[4] == cards[1])
    ) {
        printf("Four of a Kind");
    } else if (cards[0] == cards[1] && (cards[1] != cards[2] &&
               cards[2] == cards[3] && cards[3] == cards[4] ||
               cards[1] == cards[2] && cards[2] != cards[3] &&
               cards[3] == cards[4])
    ) {
        printf("Full House");
    } else if (cards[0] + 1 == cards[1] && cards[1] + 1 == cards[2] &&
               cards[2] + 1 == cards[3] && cards[3] + 1 == cards[4]
    ) {
        printf("Straight");
    } else if (cards[0] == cards[1] && cards[1] == cards[2] ||
               cards[1] == cards[2] && cards[2] == cards[3] ||
               cards[2] == cards[3] && cards[3] == cards[4]
    ) {
        printf("Three of a Kind");
    } else if (cards[0] == cards[1] && (cards[2] == cards[3] ||
               cards[3] == cards[4]) || cards[1] == cards[2] &&
               cards[3] == cards[4]
    ) {
        printf("Two Pairs");
    } else if (cards[0] == cards[1] || cards[1] == cards[2] ||
               cards[2] == cards[3] || cards[3] == cards[4]
    ) {
        printf("One Pair");
    } else {
        printf("Nothing");
    }
    return 0;
}