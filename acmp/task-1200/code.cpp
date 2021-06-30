#include <stdio.h>
#include <string>

// Time complexity: O(n)
// Space complexity: O(buf)

void staff() {
    char buf[1 + 100];
    char end;
    scanf("%s%c", &buf, &end);
    if (end != '\n') {
        staff();
    }
    std::string name(buf);
    printf("%s ", name.c_str());
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        staff();
        printf("\n");
    }
    return 0;
}