#include <stdio.h>
#include <vector>
#include <string>
#include <stack>

// Time complexity: O(n)
// Space complexity: O(n)

struct Command {

    int id;

    long long sum;
};

int main() {
    int n;
    scanf("%d", &n);
    n <<= 1;
    const int END = -1;
    std::vector<int> commands(n, END);
    char buf[1 + 3];
    for (int i = 0; i < n; i++) {
        scanf(" %s", &buf);
        if (std::string(buf) == "for") {
            scanf("%d", &commands[i]);
        }
    }
    std::stack<Command> cur;
    cur.push({END, 0});
    for (int i = 0; i < n; i++) {
        if (commands[i] != END) {
            cur.push({i, 0});
        } else {
            Command last = cur.top();
            cur.pop();
            if (last.sum == 0) {
                cur.top().sum += commands[last.id];
            } else {
                cur.top().sum += 1LL * commands[last.id] * last.sum;
            }
        }
    }
    printf("%lld", cur.top().sum);
    return 0;
}