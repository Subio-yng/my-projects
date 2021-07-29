#include <stdio.h>
#include <vector>

// Time complexity: O(n^2)
// Space complexity: O(n)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }
    for (int i = 0; i < (int) sequence.size(); i++) {
        bool left = false;
        for (int j = i - 1; j >= 0; j--) {
            if (sequence[j] > sequence[i]) {
                left = true;
                break;
            }
        }
        bool right = false;
        for (int j = i + 1; j < (int) sequence.size(); j++) {
            if (sequence[j] > sequence[i]) {
                right = true;
                break;
            }
        }
        if (right && left) {
            sequence.erase(sequence.begin() + i);
            i--;
        }
    }
    printf("%d\n", sequence.size());
    for (int i = 0; i < (int) sequence.size(); i++) {
        printf("%d ", sequence[i]);
    }
    return 0;
}