#include <stdio.h>
#include <algorithm>
#include <vector>
#include "climits"

// Time complexity: O(southSize * log(southSize) + eastSize * log(eastSize))
// Space complexity: O(southSize + eastSize)

int main() {
    int southSize;
    scanf("%d", &southSize);
    std::vector<int> southList(southSize);
    for (int i = 0; i < southSize; i++) {
        scanf("%d", &southList[i]);
    }
    std::sort(southList.begin(), southList.end());
    int eastSize;
    scanf("%d", &eastSize);
    std::vector<int> eastList(eastSize);
    for (int i = 0; i < eastSize; i++) {
        scanf("%d", &eastList[i]);
    }
    std::sort(eastList.begin(), eastList.end());
    if (eastList.back() != southList.back()) {
        printf("NO");
        return 0;
    }
    eastList.push_back(INT_MAX);
    southList.push_back(INT_MAX);
    int count = 0;
    int i = 0, j = 0;
    while (i < southSize || j < eastSize) {
        if (southList[i] > eastList[j]) {
            j++;
        } else if (southList[i] < eastList[j]) {
            i++;
        } else {
            j++;
            i++;
        }
        count++;
    }
    printf("%d", count);
    return 0;
}