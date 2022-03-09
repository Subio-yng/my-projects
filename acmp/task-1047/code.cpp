#include <stdio.h>
#include <vector>
#include <algorithm>
#include <climits>

// Time complexity: O(n! * n)
// Space complexity: O(n^2)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> table(n, std::vector<int>(n));
    std::vector<int> worker(n);
    for (int i = 0; i < n; i++) {
        worker[i] = i;
        for (int j = 0; j < n; j++) {
            scanf("%d", &table[i][j]);
        }
    }
    int minSalary = INT_MAX;
    do {
        int curSalary = 0;
        for (int i = 0; i < n; i++) {
            curSalary += table[worker[i]][i];
        }
        minSalary = std::min(minSalary, curSalary);
    } while (std::next_permutation(worker.begin(), worker.end()));
    printf("%d", minSalary);
    return 0;
}