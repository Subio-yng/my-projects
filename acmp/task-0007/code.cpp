#include <stdio.h>
#include <string>

// Time complexity: O(len(maxGold))
// Space complexity: O(buf)

std::string max(std::string a, std::string b) {
    if (a.length() > b.length()) {
        return a;
    } else if (a.length() < b.length()) {
        return b;
    }
    for (int i = 0; i < (int) a.length(); i++) {
        if (a[i] > b[i]) {
            return a;
        } else if (a[i] < b[i]) {
            return b;
        }
    }
    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char buf[1 + 100];
    scanf("%s", &buf);
    std::string maxGold(buf);
    scanf("%s", &buf);
    maxGold = max(maxGold, buf);
    scanf("%s", &buf);
    printf("%s", max(maxGold, buf).c_str());
    return 0;
}