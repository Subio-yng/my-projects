#include <stdio.h>

// Time complexity: O(1)
// Space complexity: O(1)

const int MAX_IP = 255;
const int MIN_IP = 0;

bool isOk(long long n) {
    return MIN_IP <= n && n <= MAX_IP;
}

int main() {
    long long n1 = -1;
    long long n2 = -1;
    long long n3 = -1;
    long long n4 = -1;
    scanf("%lld.%lld.%lld.%lld", &n1, &n2, &n3, &n4);
    if (isOk(n1) && isOk(n2) && 
        isOk(n3) && isOk(n4)
    ) {
        printf("Good");
    } else {
        printf("Bad");
    }
    return 0;
}