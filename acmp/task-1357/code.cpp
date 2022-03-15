#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV^2)
// Space complexity: O(nV^2)
 
void print(std::vector<int> edge) {
    printf("%d", (int) edge.size());
    for (int &e : edge) {
        printf(" %d", e);
    }
}
 
int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<std::vector<char>> edges(nV + 1, std::vector<char>(nV + 1));
    for (int i = 1; i <= nV; i++) {
        for (int j = 1; j <= nV; j++) {
            scanf(" %c", &edges[i][j]);
        }
    }
    std::vector<int> source;
    std::vector<int> stock;
    for (int i = 1; i <= nV; i++) {
        bool isSource = true;
        bool isStock = true;
        for (int j = 1; j <= nV; j++) {
            if (edges[j][i] == '1') {
                isSource = false;
            }
            if (edges[i][j] == '1') {
                isStock = false;
            }
        }
        if (isSource) {
            source.push_back(i);
        }
        if (isStock) {
            stock.push_back(i);
        }
    }
    print(source);
    printf("\n");
    print(stock);
    return 0;
}