#include <stdio.h>
#include <math.h>
  
// Time complexity: O(sqrt(n) + sqrt(m))
// Space complexity: O(1)
  
bool isPrime(int n) {
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n >= 1;
}
  
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int count = 0, div = 2;
    while (!isPrime(n) || !isPrime(m)) {
        if (isPrime(div)) {
            int tempCountN = 0;
            while (n % div == 0) {
                n /= div;
                tempCountN++;
            }
            int tempCountM = 0;
            while (m % div == 0) {
                m /= div;
                tempCountM++;
            }
            count += abs(tempCountN - tempCountM);
        }
        div++;
    }
    if (n != m) {
        count++;
        if (n != 1 && m != 1) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}