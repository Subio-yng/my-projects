#include <stdio.h>
 
// Time complexity: O(nV^2)
// Space complexity: O(1)
 
int main() {
    int nV;
    scanf("%d", &nV);
    int prevPowV = -1;
    int curPowV = 0;
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            char val;
            scanf(" %c", &val);
            if (val == '1') {
                curPowV++;
            }
        }
        if (prevPowV != -1 && prevPowV != curPowV) {
            printf("NO");
            return 0;
        }
        prevPowV = curPowV;
        curPowV = 0;
    }
    printf("YES");
    return 0;
}