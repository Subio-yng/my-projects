#include <stdio.h>
  
// Time complexity: O(1)
// Space complexity: O(1)
  
int main() {
    int n;
    scanf("%d", &n);
    int pair = n % 12;
    int bunch = n / 12 % 12;
    int box = n / 144;
    if (bunch == 11 && pair > 1) {
        bunch = 0;
        pair = 0;
        box++;
    }
    if (pair > 9) {
        pair = 0;
        bunch++;
    }
    if (bunch > 11) {
        bunch = 0;
        box++;
    }
    printf("%d %d %d", box, bunch, pair);
    return 0;
}