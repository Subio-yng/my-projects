#include <stdio.h>
#include <vector>

// Time complexity: O(n1 * m1 * n2 * m2)
// Space complexity: O(n * m)

int main() {
    int n1, m1;
    scanf("%d %d", &n1, &m1);
    std::vector<std::vector<char>> base(n1, std::vector<char>(m1));
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            scanf(" %c", &base[i][j]);
        }
    }
    int n2, m2;
    scanf(" %d %d", &n2, &m2);
    std::vector<std::vector<char>> territory(n2, std::vector<char>(m2));
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            scanf(" %c", &territory[i][j]);
        }
    }
    int count = 0;
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            bool ans = true;
            for (int k = 0; k < n1; k++) {
                for (int l = 0; l < m1; l++) {
                    if (k + i >= n2 || l + j >= m2 ||
                        base[k][l] == '#' && territory[k + i][l + j] == '.'
                        ) {
                        ans = false;
                        break;
                    }
                }
                if (!ans) {
                    break;
                }
            }
            if (ans) {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}