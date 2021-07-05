#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

struct Enrollee {

    int sumScore;

    std::string name;
};

int main() {
    int n, places;
    scanf("%d %d", &n, &places);
    places--;
    std::vector<Enrollee> list(n);
    for (int i = 0; i < n; i++) {
        char buf[1 + 10];
        int scoreMath, scoreIT, scoreRussian;
        scanf("%s %d %d %d", &buf, &scoreMath, &scoreIT, &scoreRussian);
        list[i].name = buf;
        list[i].sumScore = scoreMath + scoreIT + scoreRussian;
    }
    std::sort(list.begin(), list.end(), [](const Enrollee &left, const Enrollee &right) {
        if (left.sumScore != right.sumScore) {
            return left.sumScore > right.sumScore;
        }
        return left.name > right.name;
    });
    printf("%s %d", list[places].name.c_str(), list[places].sumScore);
    return 0;
}