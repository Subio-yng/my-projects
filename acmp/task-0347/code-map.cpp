#include <stdio.h>
#include <map>
 
// Time complexity: O(1)
// Space complexity: O(1)
 
int main() {
    const int N = 5;
    std::map<int, int> list;
    for (int i = 0; i < N; i++) {
        int card;
        scanf("%d", &card);
        list[card]++;
    }
    bool pair = false;
    bool three = false;
    int count = 1;
    int prev = list.begin()->first;
    for (auto now : list) {
        if (now.second == 5) {
            printf("Impossible");
            return 0;
        }
        if (now.second == 4) {
            printf("Four of a Kind");
            return 0;
        }
        if (now.second == 3) {
            three = true;
        }
        if (now.second == 2) {
            if (pair) {
                printf("Two Pairs");
                return 0;
            }
            pair = true;
        }
        if (now.first - 1 == prev) {
            count++;
        }
        prev = now.first;
    }
    if (three && pair) {
        printf("Full House");
    } else if (three) {
        printf("Three of a Kind");
    } else if (pair) {
        printf("One Pair");
    } else if (count == N) {
        printf("Straight");
    } else {
        printf("Nothing");
    }
    return 0;
}