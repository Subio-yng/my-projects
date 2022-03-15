#include <stdio.h>
 
// Time complexity: O(nV^2)
// Space complexity: O(1)
 
int main() {
    int nV;
    scanf("%d", &nV);
    for (int i = 0; i < nV; i++) {
        int powV = 0;
        for (int j = 0; j < nV; j++) {
            char val;
            scanf(" %c", &val);
            if (val == '1') {
                powV++;
            }
        }
        printf("%d ", powV);
    }
    return 0;
}