#include <stdio.h>
 
// Time complexity: O(log(n))
// Space complexity: O(1)
 
int main() {
    int n;
    scanf("%d", &n);
    int prevLose = 1;
    while (prevLose << 1 <= n) {
        prevLose <<= 1;
    }
    printf("%d", n - prevLose);
    return 0;
}