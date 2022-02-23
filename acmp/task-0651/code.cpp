#include <stdio.h>
#include <math.h>
  
// Time complexity: O(sqrt(n) + sqrt(m))
// Space complexity: O(1)

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

int countDivisors(int n) {
    int count = 0;
    for (int i = 2; i <= n / i; i++) {
        while (n % i == 0) {
            n /= i;
            count++;
        }
    }
    if (n != 1) {
        count++;
    }
    return count;
}
  
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", countDivisors(n / gcd(n, m)) + countDivisors(m / gcd(n, m)));
    return 0;
}