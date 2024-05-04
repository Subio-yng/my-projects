#include <bits/stdc++.h>

int getGcd(int a, int b) {
    while (b > 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", a + b - getGcd(a, b));
    return 0;
}