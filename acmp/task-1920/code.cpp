#include <bits/stdc++.h>

int main() {
    int nLine, nCircle;
    scanf("%d %d", &nLine, &nCircle);
    printf("%lld", 1LL * (nCircle + 1) * std::max(1, 2 * nLine));
    return 0;
}