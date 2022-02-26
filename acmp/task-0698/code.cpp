#include <stdio.h>
#include <map>
#include <set>
 
// Time complexity: O((n + m) * log(n))
// Space complexity: O(n)
 
struct Card {
     
    int val;
 
    char suit;
 
    static Card read() {
        char v, s;
        scanf(" %c%c", &v, &s);
        int value = v - '0';
        if (v == 'T') {
            value = 10;
        }
        if (v == 'J') {
            value = 11;
        }
        if (v == 'Q') {
            value = 12;
        }
        if (v == 'K') {
            value = 13;
        }
        if (v == 'A') {
            value = 14;
        }
        return {value, s};
    }
};

int main() {
    int n, m;
    char trump;
    scanf("%d %d %c", &n, &m, &trump);
    std::map<char, std::set<int>> cards;
    for (int i = 0; i < n; i++) {
        Card cur = Card::read();
        cards[cur.suit].insert(cur.val);
    }
    bool ans = true;
    for (int i = 0; i < m; i++) {
        Card cur = Card::read();
        auto id = cards[cur.suit].upper_bound(cur.val);
        if (cur.suit != trump && id == cards[cur.suit].end()) {
            id = cards[trump].begin();
            cur.suit = trump;
        }
        if (id == cards[cur.suit].end()) {
            ans = false;
            break;
        }
        cards[cur.suit].erase(id);
    }
    if (ans) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}