#include <stdio.h>
#include <vector>
#include <algorithm>

// Time complexity: O(n! * n)
// Space complexity: O(n^2)

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> table(n, std::vector<int>(n));
    std::vector<int> worker(n);
    int minSalary = 0;
    for (int i = 0; i < n; i++) {
        worker[i] = i;
        for (int j = 0; j < n; j++) {
            scanf("%d", &table[i][j]);
        }
        minSalary += table[i][i];
    }
    while (std::next_permutation(worker.begin(), worker.end())) {
        int curSalary = 0;
        for (int i = 0; i < n; i++) {
            curSalary += table[worker[i]][i];
        }
        minSalary = std::min(minSalary, curSalary);
    }
    printf("%d", minSalary);
    return 0;
}