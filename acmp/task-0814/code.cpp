#include <stdio.h>

// Time complexity: O(n * log(n))
// Space complexity: O(1)

bool isPrime(int n) {
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}