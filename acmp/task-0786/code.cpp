#include <stdio.h>
 
// Time complexity: O(log(n))
// Space complexity: O(1)
 
int main() {
    int n;
    scanf("%d", &n);
    int prevLose = 1;
    while (prevLose <= n / 2) {
        prevLose *= 2;
    }
    printf("%d", n - prevLose);
    return 0;
}