#include <stdio.h>
#include <vector>
 
// Time complexity: O(nV^2)
// Space complexity: O(nV^2)
 
void print(std::vector<int> edge) {
    printf("%d", (int) edge.size());
    for (int &e : edge) {
        printf(" %d", e);
    }
    printf("\n");
}
 
int main() {
    int nV;
    scanf("%d", &nV);
    std::vector<std::vector<char>> edges(nV, std::vector<char>(nV));
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            scanf(" %c", &edges[i][j]);
        }
    }
    std::vector<int> source;
    std::vector<int> sink;
    for (int i = 0; i < nV; i++) {
        bool isSource = true;
        bool isStock = true;
        for (int j = 0; j < nV; j++) {
            if (edges[j][i] == '1') {
                isSource = false;
            }
            if (edges[i][j] == '1') {
                isStock = false;
            }
        }
        if (isSource) {
            source.push_back(i + 1);
        }
        if (isStock) {
            sink.push_back(i + 1);
        }
    }
    print(source);
    print(sink);
    return 0;
}