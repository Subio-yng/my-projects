#include <stdio.h>
#include <vector>
#include <math.h>

// Time comeplexity: O(n)
// Space complexity: O(n)

int main() {
    int n;
    std::vector<int> vec;
    double s = 0;
    do {
        scanf("%d", &n);
        if (n != 0) {
            vec.push_back(n);
        }
        s += n;
    } while (n != 0);
    s /= (int) vec.size();
    double ans = 0;
    int i = 0;
    do {
        ans += pow(vec[i] * 1.0 - s, 2);
        i++;
    } while (i < (int) vec.size());
    ans = sqrt(ans / ((int) vec.size() - 1));
    printf("%.3f", ans);
    return 0;
}