#include <stdio.h>
#include <string>
#include <set>

// Time complexity: O(len(movementProgram) * log(len(movementProgram)))
// Space complexity: O(buf)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char buf[1 + 200];
    scanf("%s", &buf);
    std::string movementProgram(buf);
    std::set<int> field;
    field.insert(0);
    int x = 0, y = 0;
    int direction = 0, moveCount = 0;
    for (int i = 0; i < (int) movementProgram.length(); i++) {
        if (movementProgram[i] == 'L') {
            direction = (direction + 1) % 4;
        } else if (movementProgram[i] == 'R') {
            direction = (direction - 1) % 4;
        } else {
            if (direction == 0) {
                y--;
            } else if (direction == 1 || direction == -3) {
                x--;
            } else if (direction == 2 || direction == -2) {
                y++;
            } else if (direction == 3 || direction == -1) {
                x++;
            }
            moveCount++;
            if (field.find(y * 100 + x) != field.end()) {
                printf("%d", moveCount);
                return 0;
            }
            field.insert(y * 100 + x);
        }
    }
    printf("-1");
    return 0;
}