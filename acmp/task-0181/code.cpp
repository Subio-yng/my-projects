#include <stdio.h>
#include <unordered_map>
#include <string>

// Time complexity: O(n)
// Space complexity: O(1)
 
struct Rule {

    std::string str;

    int move;

    static Rule read() {
        std::string s;
        char buf;
        scanf("%c", &buf);
        while (buf != '\n') {
            s += buf;
            scanf("%c", &buf);
        }
        return {s, 1};
    }
};

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
        auto copy = listRules;
        for (int i = 0; i < (int) DIRECT.length(); i++) {
            listRules[DIRECT[i]].move = 1;
            for (int j = 0; j < (int) listRules[DIRECT[i]].str.length(); j++) {
                listRules[DIRECT[i]].move += copy[listRules[DIRECT[i]].str[j]].move;
            }
        }
    }
    printf("%d", listRules[direction].move);
    return 0;
}