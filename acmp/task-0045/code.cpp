#include <stdio.h>
#include <string>

// Time complexity: O(log(n))
// Space complexity: O(1)

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("10");
        return 0;
    }
    if (n == 1) {
        printf("1");
        return 0;
    }
    std::string ans;
    while (n > 1) {
        int curMaxDev = 1;
        for (int i = 2; i < 10; i++) {
            if (n % i == 0) {
                curMaxDev = i;
            }
        }
        if (curMaxDev == 1) {
            printf("-1");
            return 0;
        }
        ans += curMaxDev + '0';
        n /= curMaxDev;
    }
    std::reverse(ans.begin(), ans.end());
    printf("%s", ans.c_str());
    return 0;
}