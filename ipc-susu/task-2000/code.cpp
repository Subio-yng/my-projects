#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int k = 0;
    int l = 1;
    while (l <= 1000) {
        int c = l * l * l;
        if (a <= c && c <= b) {
            k++;
        }
        l++;
    }
    printf("%d", k);
    return 0;
}