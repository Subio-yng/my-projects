#include <stdio.h>
#include <vector>

// Time complexity: O(lenRuler * lenSlider)
// Space complexity: O(lenRuler)

int main() {
    int lenSlider;
    scanf("%d", &lenSlider);
    std::vector<bool> slider(lenSlider);
    for (int i = 0; i < lenSlider; i++) {
        char val;
        scanf(" %c", &val);
        slider[i] = val == '1';
    }
    int lenRuler;
    scanf("%d", &lenRuler);
    std::vector<int> ruler(lenRuler);
    for (int i = 0; i < lenRuler; i++) {
        scanf("%d", &ruler[i]);
    }
    int maxSum = 0;
    int bestI = 0;
    for (int i = 0; i <= lenRuler - lenSlider; i++) {
        int curSum = 0;
        for (int j = 0; j < lenSlider; j++) {
            if (slider[j]) {
                curSum += ruler[i + j];
            }
        }
        if (curSum > maxSum) {
            maxSum = curSum;
            bestI = i;
        }
    }
    for (int j = 0; j < lenSlider; j++) {
        if (slider[j]) {
            printf("%d ", ruler[bestI + j]);
        }
    }
    return 0;
}