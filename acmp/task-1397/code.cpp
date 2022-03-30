#include <stdio.h>
#include <algorithm>
  
// Time complexity: O(min(lenArea, widthArea))
// Space complexity: O(1)

bool canPlace(long long wArea,
              long long lArea,
              long long w,
              long long l,
              long long n
) {
    return (wArea / w) * (lArea / l) >= n;
}

int main() {
    long long nModules;
    scanf("%lld", &nModules);
    long long lenModule, widthModule;
    scanf("%lld %lld", &lenModule, &widthModule);
    long long lenArea, widthArea;
    scanf("%lld %lld", &lenArea, &widthArea);
    long long left = 0;
    long long right = std::min(lenArea, widthArea) / 2 + 1;
    while (left + 1 < right) {
        long long mid = (right + left) / 2;
        long long curLen = lenModule + mid * 2;
        long long curWidth = widthModule + mid * 2;
        if (canPlace(widthArea, lenArea, curWidth, curLen, nModules) ||
            canPlace(lenArea, widthArea, curWidth, curLen, nModules)
        ) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%lld", left);
    return 0;
}