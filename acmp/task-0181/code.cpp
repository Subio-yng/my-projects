#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>

// Time complexity: O(n)
// Space complexity: O(n)
 
struct Rule {

    std::string str;

    std::vector<int> move;

    static Rule read() {
        std::string s;
        char buf;
        scanf("%c", &buf);
        while (buf != '\n') {
            s += buf;
            scanf("%c", &buf);
        }
        return {s, {1}};
    }
};

void updateLastMove(std::unordered_map<char, Rule> &list, char a, int n) {
    list[a].move.push_back(1);
    for (int i = 0; i < (int) list[a].str.length(); i++) {
        list[a].move[n] += list[list[a].str[i]].move[n - 1];
    }
}

int main() {
    const std::string DIRECT = "NSWEUD";
    std::unordered_map<char, Rule> listRules;
    for (int i = 0; i < (int) DIRECT.length(); i++) {
        listRules[DIRECT[i]] = Rule::read();
    }
    int n;
    char direction;
    scanf("%c %d", &direction, &n);
    for (int cur = 1; cur < n; cur++) {
        for (int i = 0; i < (int) DIRECT.length(); i++) {
            updateLastMove(listRules, DIRECT[i], cur);
        }
    }
    printf("%d", listRules[direction].move[n - 1]);
    return 0;
}