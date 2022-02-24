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
    int size = (int) list.size();
    if (size == 1) {
        printf("Impossible");
    } else if (size == 2) {
        if (list.begin()->second == 4 || 
            list.rbegin()->second == 4
        ) {
            printf("Four of a Kind");
        } else {
            printf("Full House");
        }
    } else if (size == 3) {
        if (list.begin()->second == 2 ||
            list.rbegin()->second == 2
        ) {
            printf("Two Pairs");
        } else {
            printf("Three of a Kind");
        }
    } else if (size == 4) {
        printf("One Pair");
    } else {
        if (list.rbegin()->first - list.begin()->first == N - 1) {
            printf("Straight");
        } else {
            printf("Nothing");
        }
    }
    return 0;
}