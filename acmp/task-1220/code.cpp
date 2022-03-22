#include <stdio.h>
#include <vector>
  
// Time complexity: O(n)
// Space complexity: O(n)
 
int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> list(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    int shift;
    scanf("%d", &shift);
    shift %= n;
    for (int i = 0; i < n; i++) {
        printf("%d ", list[(i - shift + n) % n]);
    }
    return 0;
}