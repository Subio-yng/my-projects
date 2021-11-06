#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

// Time complexity: O(n * log(n))
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::string> list(n);
    for (int i = 0; i < n; i++) {
        char buf[1 + 20];
        scanf(" %s", &buf);
        list[i] = buf;
    }
    std::sort(list.begin(), list.end());
    int items = 1;
    for (int i = 1; i < n; i++) {
        if (!list[i]._Starts_with(list[i - 1])) {
            items++;
        }
    }
    printf("%d", items);
    return 0;
}