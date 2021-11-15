#include <stdio.h>
#include <vector>
#include <string>

// Time complexity: O(size)
// Space complexity: O(size)

int main() {
    int size;
    scanf("%d", &size);
    std::vector<int> room(size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &room[i]);
    }
    char buf[1 + 100];
    scanf(" %s", &buf);
    std::string commands(buf);
    int robotX = 0;
    int nextX = 1;
    bool box = false;
    for (int i = 0; i < (int) commands.length(); i++) {
        if (commands[i] == 'R') {
            nextX *= -1;
        }
        if (0 <= robotX + nextX && robotX + nextX < size) {
            if (commands[i] == 'F' && room[robotX] == room[robotX + nextX]) {
                robotX += nextX;
            }
            if (commands[i] == 'T' && !box &&
                room[robotX] <= room[robotX + nextX] &&
                room[robotX + nextX] - room[robotX] < 3 &&
                room[robotX + nextX] > 0
                ) {
                box = true;
                room[robotX + nextX]--;
            }
            if (commands[i] == 'D' && box &&
                abs(room[robotX] - room[robotX + nextX]) < 2
                ) {
                box = false;
                room[robotX + nextX]++;
            }
            if (commands[i] == 'C' && abs(room[robotX] - room[robotX + nextX]) == 1) {
                robotX += nextX;
            }
            if (commands[i] == '*' && room[robotX] == room[robotX + nextX]) {
                i -= 2;
            }
        }
    }
    printf("%d\n", robotX + 1);
    for (int i = 0; i < size; i++) {
        printf("%d ", room[i]);
    }
    return 0;
}