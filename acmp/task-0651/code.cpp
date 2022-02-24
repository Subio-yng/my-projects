#include <stdio.h>
   
// Time complexity: O(sqrt(n) + sqrt(m))
// Space complexity: O(1)
 
int getGCD(int a, int b) {
    while (b > 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
 
int countDivisors(int n) {
    if (n == 1) {
        return 0;
    }
    int count = 1;
    int div = 2;
    while (div <= n / div) {
        if (n % div == 0) {
            count++;
            n /= div;
        } else {
            div++;
        }
    }
    return count;
}
   
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int gcd = getGCD(n, m);
    printf("%d", countDivisors(n / gcd) + countDivisors(m / gcd));
    return 0;
}