#include <stdio.h>
#include <string>
#include <algorithm>

// Time complexity: O(lg(n1) * log(lg(n1)) + lg(n2) * log(lg(n2)))
// Space complexity: O(lg(n1) + lg(n2))

int getMax(int n);

int getMin(int n);

int getMin(int n) {
    if (n < 0) {
        return -getMax(-n);
    } else {
        std::string minNum = std::to_string(n);
        std::sort(minNum.begin(), minNum.end());
        int i = 0;
        while (minNum[i] == '0') {
            i++;
        }
        std::swap(minNum[i], minNum[0]);
        return atoi(minNum.c_str());
    }
}

int getMax(int n) {
    if (n < 0) {
        return -getMin(-n);
    } else {
        std::string maxNum = std::to_string(n);
        std::sort(maxNum.rbegin(), maxNum.rend());
        return atoi(maxNum.c_str());
    }
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("%d", getMax(n1) - getMin(n2));
    return 0;
}