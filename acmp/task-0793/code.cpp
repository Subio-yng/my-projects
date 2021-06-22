#include <stdio.h>

// Time complexity: O(n * log(n) * sqrt(n))
// Space complexity: O(1)

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

int sumNum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int sumPrime(int n) {
    int sum = 0, temp = n;
    int dev = 2;
    while (n > 1) {
        if (dev * dev > temp) {
            break;
        }
        if (isPrime(dev) && n % dev == 0) {
            n /= dev;
            sum += sumNum(dev);
        } else {
            dev++;
        }
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (true) {
        int num;
        int code = scanf("%d", &num);
        if (code == EOF) {
            break;
        }
        if (sumNum(num) == sumPrime(num)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    return 0;
}