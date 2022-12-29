#include <bits/stdc++.h>

// Time complexity: O(nQ * n * log(nLimit))
// Space complexity: O(nLimit)

bool canDrive(int start,
              int end,
              int mid,
              const std::vector<int> &speedLimit,
              const std::vector<int> &partLen,
              const std::vector<int> &partSpeed
) {
    static const long double EPS = 1e-5;
    long double curTime = 0;
    for (int j = 0; j < (int) partLen.size(); j++) {
        curTime += (long double) partLen[j] / (partSpeed[j] + speedLimit[mid]);
    }
    return curTime - EPS <= end - start;
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> partSpeed(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &partSpeed[i]);
    }
    std::vector<int> partLen(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &partLen[i]);
    }
    int nLimit;
    scanf("%d", &nLimit);
    std::vector<int> speedLimit(nLimit + 1);
    speedLimit[1] = 0;
    for (int i = 2; i <= nLimit; i++) {
        scanf("%d", &speedLimit[i]);
    }
    std::vector<int> fine(nLimit + 1, 0);
    for (int i = 1; i <= nLimit; i++) {
        scanf("%d", &fine[i]);
    }
    int nQ;
    scanf("%d", &nQ);
    for (int i = 0; i < nQ; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        int left = 0;
        int right = nLimit + 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (canDrive(start, end, mid, speedLimit, partLen, partSpeed)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        printf("%d\n", fine[left]);
    }
    return 0;
}